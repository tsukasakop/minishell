#!/usr/bin/env bash

DEBUG_FILE="${DEBUG_FILE-/dev/null}"

main()
{
    echo "Run ${0##*/} on bash $BASH_VERSION" > "$DEBUG_FILE"
    # ここに処理を追加
    local DIR="$1"
    for f in $(find "$DIR" -type f)
    do
        echo "Target: $f"
        make valgrind "$f"
    done
}

if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    main "$@"
fi

