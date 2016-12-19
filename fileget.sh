#/bash/sh

# realpath の存在確認
if ! type realpath > /dev/null 2>&1; then
    echo "realpath が見つかりません。" >&2
    exit 1
fi

BASE_DIR=`realpath \`dirname ${0}\``

# 場所移動
cd ${BASE_DIR}

# firmware_armstub が存在しなければ web から取得して展開する
if [ ! -e ${BASE_DIR}/firmware_armstub ]; then
    # ファイルダウンロード
    mkdir firmware_armstub
    wget https://dl.dropboxusercontent.com/u/3669512/temp/firmware_armstub.zip -O firmware_armstub/firmware_armstub.zip

    # 展開
    cd ${BASE_DIR}/firmware_armstub
    unzip firmware_armstub.zip
    cd ${BASE_DIR}
fi

# gcc-linaro-6.2.1-2016.11-i686-mingw32_aarch64-linux-gnu が存在しなければ web から取得して展開する
if [  ! -e ${BASE_DIR}/gcc-linaro-6.2.1-2016.11-i686-mingw32_aarch64-linux-gnu ]; then
    # ファイルダウンロード
    wget https://releases.linaro.org/components/toolchain/binaries/latest/aarch64-linux-gnu/gcc-linaro-6.2.1-2016.11-i686-mingw32_aarch64-linux-gnu.tar.xz

    # 展開
    tar xfv gcc-linaro-6.2.1-2016.11-i686-mingw32_aarch64-linux-gnu.tar.xz
fi
