#!/usr/bin/env bash

ROOT_DIR="$(git -C "${0%/*}" rev-parse --show-toplevel)"
DEBUG_FILE="${DEBUG_FILE-/dev/null}"

main()
{
    set -e
    echo "Run ${0##*/} on bash $BASH_VERSION" > "$DEBUG_FILE"
    # ここに処理を追加
    cd "$ROOT_DIR"
    local Error=0
    while IFS= read line; do
        if [ "$(echo $line | awk -F':' '{print $1}')" != "Error" ]; then
            local FILE="$(echo $line | awk -F':' '{print $1}')"
            local STATUS="$(echo $line | awk -F':' '{print $2}')"
            local HEAD="$line"
        else
            if [ ! -z "$HEAD" ]; then
                echo "$HEAD"
            fi
            local HEAD=""
            echo "$line"
            local Error=1
        fi
    done <<<$(norminette src/*/*.c include/*.h | grep Error | grep -v WRONG_SCOPE_COMMENT | grep -v LINE_TOO_LONG | grep -v TOO_MANY_LINES)
    if [ "$Error" -eq 0 ]; then
        echo "OK!"
        exit 0
    else
        exit 1
    fi
}

if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    main "$@"
fi
