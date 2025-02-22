#!/usr/local/bin/bash

export PS1='minishell$ '
MISH="${MISH-$(git -C "${0%/*}" rev-parse --show-toplevel)/minishell}"
BASH="bash --norc --noprofile -i"
TESTCASE_DIR="${0%/*}/test-cases"

STDOUT_EXT=".out"
STDERR_EXT=".err"
STATUS_EXT=".sta"
RESULT_DIR="/tmp/debug-minishell"


assert-simple()
{
    mkdir -p "$RESULT_DIR"
    $MISH <&"$MISH_FD" \ 1>"$RESULT_DIR/mish$STDOUT_EXT" \
        2>"$RESULT_DIR/mish$STDERR_EXT"
    echo "$?" > "$RESULT_DIR/mish$STATUS_EXT"

    $BASH <&"$BASH_FD" \
        1>"$RESULT_DIR/bash$STDOUT_EXT" \
        2>"$RESULT_DIR/bash$STDERR_EXT"
    echo "$?" > "$RESULT_DIR/bash$STATUS_EXT"

    local IS_FAILURE=0
    if ! diff "$RESULT_DIR/mish$STDOUT_EXT" "$RESULT_DIR/bash$STDOUT_EXT"; then
        echo "Error: diff on stdout" >&2
        IS_FAILURE=1
    fi
    if ! diff "$RESULT_DIR/mish$STDERR_EXT" "$RESULT_DIR/bash$STDERR_EXT"; then
        echo "Error: diff on stderr" >&2
        IS_FAILURE=1
    fi
    if ! diff "$RESULT_DIR/mish$STATUS_EXT" "$RESULT_DIR/bash$STATUS_EXT"; then
        echo "Error: diff on exit status" >&2
        IS_FAILURE=1
    fi
    return "$IS_FAILURE"
}

test-string()
{
    local STRING="${1:?}"

    exec {BASH_FD}<<<"$STRING"
    exec {MISH_FD}<<<"$STRING"

    assert-simple
    local STATUS="$?"

    exec {BASH_FD}<&-
    exec {MISH_FD}<&-

    if [ "$STATUS" -eq 0 ]; then
        echo "Success: \"$STRING\"" >&2
    else
        echo "Failure: \"$STRING\"" >&2
    fi
    return "$STATUS"
    
}

test-file()
{
    local FILE="${1:?}" 

    exec {BASH_FD}<"$FILE"
    exec {MISH_FD}<"$FILE"

    assert-simple
    local STATUS="$?"

    exec {BASH_FD}<&-
    exec {MISH_FD}<&-

    if [ "$STATUS" -eq 0 ]; then
        echo "Success: $FILE" >&2
    else
        echo "Failure: $FILE" >&2
    fi
    return "$STATUS"
}

test-files()
{
    local STATUS=0;
    while IFS= read -r -d '' file; do
        test-file "$file" || STATUS=1
    done < <(find "${1:?}"/* -print0)
    return "$STATUS"
}

main()
{
    if [ ! -f "$MISH" ]; then
        echo "minishell is not found on '$MISH'" >&2
        echo "to set correct path:" >&2
        echo "  export MISH='/path/to/minishell'" >&2
        return 1
    fi
    if [ -z "$1" ]; then
        test-files "$TESTCASE_DIR"
    elif [ -f "$1" ]; then
        test-file "$1"
    else
        test-string "$1"
    fi
    return $?
}

if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    main "$@"
fi
