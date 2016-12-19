#/bin/sh

# realpath の存在確認
if ! type realpath > /dev/null 2>&1; then
    echo "realpath が見つかりません。" >&2
    exit 1
fi

BASE_DIR=`realpath \`pwd\``

export PATH=${BASE_DIR}/gcc-linaro-6.2.1-2016.11-i686-mingw32_aarch64-linux-gnu/bin:${PATH}
