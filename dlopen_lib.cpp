#include "dlopen_lib.h"

configuration_impl::configuration_impl()
    : plugin_impl<configuration_impl>("hello", 1, plugin_type_e::APPLICATION_PLUGIN)
{
    std::cout << "this is C constructor -> " << this << std::endl;
}

configuration_impl::~configuration_impl()
{

}

void configuration_impl::show()
{
    std::cout << "show_c" << std::endl;
}

extern "C" {

create_b create_lib() {
    std::cout << "this function called" << std::endl;
    return configuration_impl::get_plugin;
}

} // extern "C"
