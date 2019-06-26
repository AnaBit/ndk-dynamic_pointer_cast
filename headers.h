#pragma once

#include <iostream>
#include <memory>

class configuration {
public:
    virtual ~configuration() {}
    virtual void show() = 0;
};

enum class plugin_type_e : uint8_t {
    APPLICATION_PLUGIN,
    PRE_CONFIGURATION_PLUGIN,
    CONFIGURATION_PLUGIN,
    SD_RUNTIME_PLUGIN
};

class plugin {
public:
    virtual ~plugin() {}

    virtual uint32_t get_plugin_version() const = 0;
    virtual const std::string &get_plugin_name() const = 0;
    virtual plugin_type_e get_plugin_type() const = 0;
};


template<class Plugin_>
class plugin_impl : public plugin {
public:
    static std::shared_ptr<plugin> get_plugin() {
        return std::make_shared<Plugin_>();
    }

    plugin_impl(const std::string &_name, uint32_t _version,
                plugin_type_e _type) {
        name_ = _name;
        version_ = _version;
        type_ = _type;
    }

    const std::string &get_plugin_name() const {
        return name_;
    }

    uint32_t get_plugin_version() const {
        return version_;
    }

    plugin_type_e get_plugin_type() const {
        return type_;
    }

private:
    uint32_t version_;
    std::string name_;
    plugin_type_e type_;
};

typedef std::shared_ptr<plugin> (*create_b)(void);
typedef create_b (*dlopen_func) (void);
