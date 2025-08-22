#pragma once
#include "types.hpp"

namespace cmn {
namespace ss {
using namespace cmn::types;

template< typename... Args >
constexpr auto snprintf( char* buffer, usize size, str format, Args const&... args ) noexcept -> usize
{
    if( not buffer or size == 0 ) [[unlikely]] {
        return 0;
    }

    usize pos = 0;
    str fmt = format;

    if constexpr( sizeof...( args ) == 0 ) {
        while( *fmt and pos < size - 1 ) {
            buffer[pos++] = *fmt++;
        }
    }
    else {
        str arg_array[sizeof...( args )] = { args... };
        constexpr usize ARG_COUNT = sizeof...( args );
        usize arg_index = 0;

        while( *fmt and pos < size - 1 ) {
            if( *fmt == '%' and *( fmt + 1 ) == 's' and arg_index < ARG_COUNT ) {
                fmt += 2; // skip "%s"
                str sub = arg_array[arg_index++];

                if( sub ) {
                    while( *sub and pos < size - 1 ) {
                        buffer[pos++] = *sub++;
                    }
                }
            }
            else {
                buffer[pos++] = *fmt++;
            }
        }
    }

    buffer[pos] = '\0';
    return pos;
}

} // namespace ss
} // namespace cmn
