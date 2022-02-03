// Measure Execution time if compiled with asr_time flag
#ifdef asr_time
    auto begin = chrono::high_resolution_clock::now();
#endif


#ifdef asr_time
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif
