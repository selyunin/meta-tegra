LICENSE = "Proprietary"

inherit l4t_deb_pkgfeed cuda features_check

HOMEPAGE = "http://developer.nvidia.com/tensorrt"

L4T_DEB_GROUP = "tensorrt"

SRC_COMMON_DEBS = "\
    libnvinfer-samples_${PV}+cuda10.2_all.deb;downloadfilename=libnvinfer-samples_${PV}+cuda10.2_all.deb;name=samples;subdir=tensorrt \
"

SRC_URI:append = " file://0001-Makefile-fix-cross-compilation-issues.patch"

SRC_URI[samples.sha256sum] = "711ba173603270a836d844b71edd6da22322be7fd5e66ad683a5a34014514478"

COMPATIBLE_MACHINE = "(tegra)"

REQUIRED_DISTRO_FEATURES = "opengl"

LIC_FILES_CHKSUM = "file://../../../share/doc/libnvinfer-samples/copyright;md5=713c2de2adb0f371a903b9fe20431bab"

S = "${WORKDIR}/tensorrt/usr/src/tensorrt/samples"

DEPENDS = "cuda-cudart cudnn tegra-libraries-multimedia-utils tensorrt-core tensorrt-plugins libglvnd"

EXTRA_OEMAKE = ' \
    CUDA_INSTALL_DIR="${STAGING_DIR_HOST}/usr/local/cuda-${CUDA_VERSION}" \
    CUDNN_INSTALL_DIR="${STAGING_DIR_HOST}/usr/lib" \
    TRT_LIB_DIR="${STAGING_DIR_HOST}/usr/lib" \
    TARGET="${TARGET_ARCH}" BUILD_TYPE="release" \
'

TARGET_CC_ARCH += "${LDFLAGS}"

do_configure() {
    :
}
