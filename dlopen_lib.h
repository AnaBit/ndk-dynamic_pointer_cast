#pragma once

#include <memory>
#include <iostream>

#include "headers.h"

class configuration_impl :
        public configuration,
        public plugin_impl<configuration_impl>,
        public std::enable_shared_from_this<configuration_impl> {
public:
    configuration_impl();

    ~configuration_impl();

    void show();

private:
    int c;
};
