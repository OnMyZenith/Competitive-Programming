@echo off
for /l %%x in (1, 1, 99999) do (
    echo %%x
    gen %%x > in
    a < in > a_out 
    validator
    fc /w out t_out > diagnostics || exit /b
)
echo All Tests Passed!!