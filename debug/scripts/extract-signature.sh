#!/usr/bin/env bash

DEBUG_FILE="${DEBUG_FILE-/dev/null}"
SRC_DIR="src"

show-mother-branch()
{
    local EXIT
    git show-branch | grep '*' | grep -v "$(git rev-parse --abbrev-ref HEAD)" | head -1 | awk -F'[]~^[]' '{print $2}'
    return "$?"
}

new-files-from-branch()
{
    local BRANCH="${1-$(show-mother-branch)}"

    local COMMITED_NEW_FILES="$(git diff $BRANCH --name-status | grep -E '^A' | awk '{print $2}')"
    local UNTRACKED_FILES="$(git status -s | grep -E '^\?\? ' | awk '{print $2}')"
    printf "%s\n%s" "$UNTRACKED_FILES" "$COMMITED_NEW_FILES"
    return "$?"
}

extract-signature()
{
    local SOURCE="$@"

    cat $SOURCE | grep -E '^{' -B 1 | grep -v { | grep -v '\-\-' | awk '{print $0";"}'
}

main()
{
    set -e
    echo "Run ${0##*/} on bash $BASH_VERSION" > "$DEBUG_FILE"
    # ここに処理を追加
    local NEW_FILES="${@-$(new-files-from-branch)}"
    local C_FILES="$(find $NEW_FILES -type f | grep -E '^'"$SRC_DIR"'/.*\.c$')"
    echo "extract signature from: $C_FILES" > "$DEBUG_FILE"
    extract-signature "$C_FILES"
}

if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    main "$@"
fi
