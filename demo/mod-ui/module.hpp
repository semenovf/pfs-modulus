////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2019,2020 Vladislav Trifochkin
//
// This file is part of [pfs-modulus](https://github.com/semenovf/pfs-modulus) library.
//
// Changelog:
//      2019.12.23 Initial version
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "modulus.hpp"

namespace mod {
namespace ui {

class module : public modulus::async_module
{
public:
    MODULUS_DECL_EMITTERS
    MODULUS_DECL_DETECTORS

private:
    virtual bool on_loaded () override;
    virtual bool on_start () override;
    virtual bool on_finish () override;
    virtual int run () override;

    modulus::sigslot_ns::signal<> emitUiReady;
};

}} // namespace mod::ui