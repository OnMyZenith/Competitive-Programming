@echo off
for /l %%x in (1, 1, 99999) do (
    echo %%x
    gen %%x > in
    INTCONCA < in > a_out 
    b < in > b_out
    fc /w a_out b_out > diagnostics || exit /b
)
echo All Tests Passed!!