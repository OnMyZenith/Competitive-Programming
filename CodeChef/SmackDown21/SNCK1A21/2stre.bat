@echo off
for /l %%x in (1, 1, 99999) do (
    echo %%x
    gen2 %%x > in
    EQBEAUTY < in > a_out 
    abhaypp < in > abh_out 
    fc /w abh_out a_out > diagnostics || exit /b
)
echo All Tests Passed!!