#define CATCH_CONFIG_RUNNER
#if defined(_MSC_VER) && defined(MEMORY_LEAK_DETECT)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif
#include <stdlib.h>
#include <check.h>

extern Suite *main_suite();

int main( int argc, char* argv[] ) {
    int ret;
#if defined(_MSC_VER) && defined(MEMORY_LEAK_DETECT)
    _CrtMemState _checkpoint_start;
    _CrtMemState _checkpoint_end;
    _CrtMemState _checkpoint_diff;

    int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    flag |= _CRTDBG_LEAK_CHECK_DF;
    flag |= _CRTDBG_ALLOC_MEM_DF;
    _CrtSetDbgFlag ( flag );
    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG );
    _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDERR );
    _CrtMemCheckpoint(&_checkpoint_start);
#endif
    /**NOTICE: Исключаем влияние Check на анализ памяти */
    {
        Suite *suite;
        SRunner *runner;
        int failed;

        suite = main_suite();
        runner = srunner_create(suite);
        srunner_run_all(runner, CK_NORMAL);
        failed = srunner_ntests_failed(runner);
        srunner_free(runner);
        ret = failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
    }
#if defined(_MSC_VER) && defined(MEMORY_LEAK_DETECT)
    _CrtMemCheckpoint(&_checkpoint_end);
    if (_CrtMemDifference(&_checkpoint_diff, &_checkpoint_start, &_checkpoint_end))
        _CrtMemDumpStatistics( &_checkpoint_diff );
    _CrtDumpMemoryLeaks();
#endif
    return ret;
}
