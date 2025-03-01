#!/usr/bin/env bash

DEBUG_FILE="${DEBUG_FILE-/dev/null}"

main()
{
    set -e
    echo "Run ${0##*/} on bash $BASH_VERSION" > "$DEBUG_FILE"
    # ここに処理を追加
    ROOT_DIR="$(git rev-parse --show-toplevel)"
    local DIR="src/${1%/*}"
    local FILE="${1##*/}"
    local NAME="${FILE%.c}"
    local PATH="$DIR/$NAME.c"

    echo "dir: $DIR" > "$DEBUG_FILE"
    echo "name: $NAME" > "$DEBUG_FILE"
    echo "path: $PATH" > "$DEBUG_FILE"
    pwd > "$DEBUG_FILE"

    if [ -e "$PATH" ]; then
        echo "$PATH is already exist" >/dev/stderr
        return 1
    fi
    /bin/mkdir -p "$DIR"
    /bin/cat <<EOF >"$PATH"
# include <minishell.h>

/*
 * Function: $NAME
 * ----------------------------
 */
void	$NAME()
{
}
EOF
    echo "$PATH created" >/dev/stderr
}

if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    main "$@"
fi

