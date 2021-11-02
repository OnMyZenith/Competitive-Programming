@echo off
for /l %%x in (1, 1, 99999) do (
    echo %%x
    gen_tree2 %%x > in
    e < in > a_out 
    t < in > t_out
    fc /w a_out t_out > diagnostics || exit /b
)
echo All Tests Passed!!