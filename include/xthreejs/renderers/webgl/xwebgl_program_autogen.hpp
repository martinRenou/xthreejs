#ifndef XTHREE_WEBGL_PROGRAM_HPP
#define XTHREE_WEBGL_PROGRAM_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"

namespace xthree
{
    //
    // webgl_program declaration
    //

    template<class D>
    class xwebgl_program : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xwebgl_program();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_program = xw::xmaterialize<xwebgl_program>;

    using webgl_program_generator = xw::xgenerator<xwebgl_program>;

    //
    // webgl_program implementation
    //


    template <class D>
    inline void xwebgl_program<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xwebgl_program<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xwebgl_program<D>::xwebgl_program()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_program<D>::set_defaults()
    {
        this->_model_name() = "WebGLProgramModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xwebgl_program));
//}
#endif