/*~--------------------------------------------------------------------------~*
 *  @@@@@@@@  @@           @@@@@@   @@@@@@@@ @@
 * /@@/////  /@@          @@////@@ @@////// /@@
 * /@@       /@@  @@@@@  @@    // /@@       /@@
 * /@@@@@@@  /@@ @@///@@/@@       /@@@@@@@@@/@@
 * /@@////   /@@/@@@@@@@/@@       ////////@@/@@
 * /@@       /@@/@@//// //@@    @@       /@@/@@
 * /@@       @@@//@@@@@@ //@@@@@@  @@@@@@@@ /@@
 * //       ///  //////   //////  ////////  //
 *
 * Copyright (c) 2016 Los Alamos National Laboratory, LLC
 * All rights reserved
 *~--------------------------------------------------------------------------~*/
/*!
 * \file burton_entity_types.h
 * \authors bergen
 * \date Initial file creation: Nov 15, 2015
 ******************************************************************************/

#pragma once

//! user includes
#include "ale/geom/shapes/geometric_shapes.h"
#include "ale/mesh/burton/burton_mesh_traits.h"
#include "ale/utils/errors.h"
#include "flecsi/mesh/mesh_types.h"


namespace ale {
namespace mesh {

////////////////////////////////////////////////////////////////////////////////
//! \class burton_vertex_t burton_entity_types.h
//! \brief The burton_vertex_t type provides an interface for managing
//!   geometry and state associated with mesh vertices.
//!
//! \tparam N The domain of the vertex.
////////////////////////////////////////////////////////////////////////////////
template< std::size_t N >
class burton_vertex_t {};

////////////////////////////////////////////////////////////////////////////////
//! \class burton_vertex_t burton_entity_types.h
//! \brief The burton_vertex_t type provides an interface for managing
//!   geometry and state associated with mesh vertices.
//!
//! \tparam N The domain of the vertex.
////////////////////////////////////////////////////////////////////////////////
template<>
class burton_vertex_t<2> : 
    public flecsi::mesh_entity_t<0, burton_mesh_traits_t<2>::num_domains>
{
public:

  //============================================================================
  // Typedefs
  //============================================================================

  //! the flecsi mesh topology type
  using mesh_topology_base_t =  flecsi::mesh_topology_base_t;
 
  //! the mesh traits
  using mesh_traits_t = burton_mesh_traits_t<2>;

  //! Number of domains in the burton mesh.
  static constexpr auto num_domains = mesh_traits_t::num_domains;

  //! Number of domains in the burton mesh.
  static constexpr auto num_dimensions = mesh_traits_t::num_dimensions;

  //! The domain of the entity
  static constexpr auto domain = 0;

  //! Handle for accessing state at vertex.
  using data_t = typename mesh_traits_t::data_t;

  //! Type containing coordinates of the vertex.
  using point_t = typename mesh_traits_t::point_t;

  //! The bitfield.
  using bitfield_t = typename mesh_traits_t::bitfield_t;

  //! The boundary id type
  using tag_t = typename mesh_traits_t::tag_t;
  using tag_list_t = typename mesh_traits_t::tag_list_t;

  //============================================================================
  // Constructors
  //============================================================================

  //! Constructor
  burton_vertex_t(mesh_topology_base_t & mesh) : mesh_(&mesh) 
  {}

  //! dissallow copying
  burton_vertex_t( burton_vertex_t & ) = delete;
  burton_vertex_t & operator=( burton_vertex_t & ) = delete;

  //! dissallow moving
  burton_vertex_t( burton_vertex_t && ) = delete;
  burton_vertex_t & operator=( burton_vertex_t && ) = delete;

  //============================================================================
  // Accessors / Modifiers
  //============================================================================

  //! \brief Get the coordinates at a vertex from the state handle.
  //! \return coordinates of vertex.
  const point_t & coordinates() const;

  //! \brief Get the coordinates at a vertex from the state handle.
  //! \return coordinates of vertex.
  //! \remark this is the non const version
  point_t & coordinates();

  //! is this a boundary
  bool is_boundary() const;

  //! get all entity tags
  const tag_list_t & tags() const;
  //! tag entity
  void tag(const tag_t & tag);
  //! does entity have a tag
  bool has_tag(const tag_t & tag);


  //! \brief reset the mesh pointer
  void reset(mesh_topology_base_t & mesh) 
  { 
    mesh_ = &mesh; 
  }

  //============================================================================
  // Private Data
  //============================================================================
  
private:
  
  //! a reference to the mesh topology
  const mesh_topology_base_t * mesh_ = nullptr;

}; // class burton_vertex_t


////////////////////////////////////////////////////////////////////////////////
//! \class burton_vertex_t burton_entity_types.h
//! \brief The burton_vertex_t type provides an interface for managing
//!   geometry and state associated with mesh vertices.
//!
//! \tparam N The domain of the vertex.
////////////////////////////////////////////////////////////////////////////////
template<>
class burton_vertex_t<3> : 
    public flecsi::mesh_entity_t<0, burton_mesh_traits_t<2>::num_domains>
{
public:

  //============================================================================
  // Typedefs
  //============================================================================

  //! the flecsi mesh topology type
  using mesh_topology_base_t =  flecsi::mesh_topology_base_t;
 
  //! the mesh traits
  using mesh_traits_t = burton_mesh_traits_t<3>;

  //! Number of domains in the burton mesh.
  static constexpr auto num_domains = mesh_traits_t::num_domains;

  //! Number of domains in the burton mesh.
  static constexpr auto num_dimensions = mesh_traits_t::num_dimensions;

  //! The domain of the entity
  static constexpr auto domain = 0;

  //! Handle for accessing state at vertex.
  using data_t = typename mesh_traits_t::data_t;

  //! Type containing coordinates of the vertex.
  using point_t = typename mesh_traits_t::point_t;

  //! The bitfield.
  using bitfield_t = typename mesh_traits_t::bitfield_t;

  //! The boundary id type
  using tag_t = typename mesh_traits_t::tag_t;
  using tag_list_t = typename mesh_traits_t::tag_list_t;

  //============================================================================
  // Constructors
  //============================================================================

  //! Constructor
  burton_vertex_t(mesh_topology_base_t & mesh) : mesh_(&mesh) 
  {}

  //! dissallow copying
  burton_vertex_t( burton_vertex_t & ) = delete;
  burton_vertex_t & operator=( burton_vertex_t & ) = delete;

  //! dissallow moving
  burton_vertex_t( burton_vertex_t && ) = delete;
  burton_vertex_t & operator=( burton_vertex_t && ) = delete;

  //============================================================================
  // Accessors / Modifiers
  //============================================================================

  //! \brief Get the coordinates at a vertex from the state handle.
  //! \return coordinates of vertex.
  const point_t & coordinates() const;

  //! \brief Get the coordinates at a vertex from the state handle.
  //! \return coordinates of vertex.
  //! \remark this is the non const version
  point_t & coordinates();

  //! is this a boundary
  bool is_boundary() const;

  //! get all entity tags
  const tag_list_t & tags() const;
  //! tag entity
  void tag(const tag_t & tag);
  //! does entity have a tag
  bool has_tag(const tag_t & tag);

  //! \brief reset the mesh pointer
  void reset(mesh_topology_base_t & mesh) 
  { 
    mesh_ = &mesh; 
  }

  //============================================================================
  // Private Data
  //============================================================================
  
private:
  
  //! a reference to the mesh topology
  const mesh_topology_base_t * mesh_ = nullptr;

}; // class burton_vertex_t



} // namespace mesh
} // namespace ale


/*~-------------------------------------------------------------------------~-*
 * Formatting options
 * vim: set tabstop=2 shiftwidth=2 expandtab :
 *~-------------------------------------------------------------------------~-*/
