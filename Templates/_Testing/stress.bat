@echo off
for /l %%x in (1, 1, 99999) do (
    echo %%x
    gen %%x > int
    a < int > a_out 
    t < int > t_out 
    fc /w a_out t_out > diagnostics || exit /b
)
echo All Tests Passed!!