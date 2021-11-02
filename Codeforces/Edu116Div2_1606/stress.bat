@echo off
for /l %%x in (1, 1, 99999) do (
    echo %%x
    gen %%x > in
    b < in > b_out 
    t < in > t_out 
    fc /w b_out t_out > diagnostics || exit /b
)
echo All Tests Passed!!