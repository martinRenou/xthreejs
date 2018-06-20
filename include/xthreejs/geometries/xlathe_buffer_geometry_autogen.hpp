#ifndef XTHREE_LATHE_BUFFER_GEOMETRY_HPP
#define XTHREE_LATHE_BUFFER_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_buffer_geometry_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // lathe_buffer_geometry declaration
    //

    template<class D>
    class xlathe_buffer_geometry : public xbase_buffer_geometry<D>
    {
    public:

        using base_type = xbase_buffer_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::vector<std::vector<double>>, derived_type, points, std::vector<std::vector<double>>({}));
        XPROPERTY(int, derived_type, segments, 12);
        XPROPERTY(double, derived_type, phiStart, 0);
        XPROPERTY(double, derived_type, phiLength, 6.283185307179586);
        XPROPERTY(std::string, derived_type, type, "LatheBufferGeometry");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xlathe_buffer_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using lathe_buffer_geometry = xw::xmaterialize<xlathe_buffer_geometry>;

    using lathe_buffer_geometry_generator = xw::xgenerator<xlathe_buffer_geometry>;

    //
    // lathe_buffer_geometry implementation
    //


    template <class D>
    inline void xlathe_buffer_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(points, state, buffers);
        xw::set_patch_from_property(segments, state, buffers);
        xw::set_patch_from_property(phiStart, state, buffers);
        xw::set_patch_from_property(phiLength, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xlathe_buffer_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(points, patch, buffers);
        xw::set_property_from_patch(segments, patch, buffers);
        xw::set_property_from_patch(phiStart, patch, buffers);
        xw::set_property_from_patch(phiLength, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xlathe_buffer_geometry<D>::xlathe_buffer_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xlathe_buffer_geometry<D>::set_defaults()
    {
        this->_model_name() = "LatheBufferGeometryModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xlathe_buffer_geometry>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xlathe_buffer_geometry>;
        extern template xw::xmaterialize<xthree::xlathe_buffer_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xlathe_buffer_geometry>>;
        extern template class xw::xgenerator<xthree::xlathe_buffer_geometry>;
        extern template xw::xgenerator<xthree::xlathe_buffer_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xlathe_buffer_geometry>>;
    #endif
#endif

#endif