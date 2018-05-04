#ifndef XTHREE_TORUS_BUFFER_GEOMETRY_HPP
#define XTHREE_TORUS_BUFFER_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_buffer_geometry_autogen.hpp"

namespace xthree
{
    //
    // torus_buffer_geometry declaration
    //

    template<class D>
    class xtorus_buffer_geometry : public xbase_buffer_geometry<D>
    {
    public:

        using base_type = xbase_buffer_geometry<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, radius, 1);
        XPROPERTY(double, derived_type, tube, 0.4);
        XPROPERTY(int, derived_type, radialSegments, 8);
        XPROPERTY(int, derived_type, tubularSegments, 6);
        XPROPERTY(double, derived_type, arc, 6.283185307179586);


    protected:

        xtorus_buffer_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using torus_buffer_geometry = xw::xmaterialize<xtorus_buffer_geometry>;

    using torus_buffer_geometry_generator = xw::xgenerator<xtorus_buffer_geometry>;

    //
    // torus_buffer_geometry implementation
    //


    template <class D>
    inline void xtorus_buffer_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(tube, state, buffers);
        xw::set_patch_from_property(radialSegments, state, buffers);
        xw::set_patch_from_property(tubularSegments, state, buffers);
        xw::set_patch_from_property(arc, state, buffers);
    }

    template <class D>
    inline void xtorus_buffer_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(tube, patch, buffers);
        xw::set_property_from_patch(radialSegments, patch, buffers);
        xw::set_property_from_patch(tubularSegments, patch, buffers);
        xw::set_property_from_patch(arc, patch, buffers);
    }

    template <class D>
    inline xtorus_buffer_geometry<D>::xtorus_buffer_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xtorus_buffer_geometry<D>::set_defaults()
    {
        this->_model_name() = "TorusBufferGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xtorus_buffer_geometry));
//}
#endif