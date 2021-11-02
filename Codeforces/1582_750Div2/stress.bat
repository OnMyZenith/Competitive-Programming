@echo off
for /l %%x in (1, 1, 99999) do (
    echo %%x
    gen %%x > in
    MAXDISTKT < in > a_out 
    MAXDISTKT_ak < in > ak_out 
    validator < a_out > a_out_f
    validator < ak_out > ak_out_f
    fc /w a_out_f ak_out_f > diagnostics || exit /b
)
echo All Tests Passed!!