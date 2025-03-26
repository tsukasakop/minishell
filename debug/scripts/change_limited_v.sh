#!/bin/bash
ulimit -Sv 1002400  # 4110 に制限
./minishell
ulimit -Sv unlimited  # 制限解除
