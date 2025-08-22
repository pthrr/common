#include <common/bits.hpp>
#include <common/result.hpp>
#include <common/snprintf.hpp>
#include <common/traits.hpp>
#include <common/types.hpp>

auto main() -> int
{
    char arr[16];
    cmn::ss::snprintf( arr, sizeof( arr ), "some %s", "test" );
    return 0;
}
