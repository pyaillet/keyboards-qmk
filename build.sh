#!/usr/bin/env bash

CURRENT_DIR="$(pwd)"

cd ../qmk_firmware

qmk flash -kb pya_keyboards -km pya-ergol

cd "${CURRENT_DIR}"

