@echo off
for /l %%x in (1, 1, 99999) do (
    echo %%x
    gen %%x > in
    c < in > c_out 
    t < in > t_out
    fc /w c_out t_out > diagnostics || exit /b
)
echo All Tests Passed!!