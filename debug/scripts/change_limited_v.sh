#!/bin/bash
ulimit -Sv 4100  # 4110 に制限
./minishell
ulimit -Sv unlimited  # 制限解除
