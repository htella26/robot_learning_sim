/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the COPYING file, which can be found at the root of the source code       *
 * distribution tree, or in https://www.hdfgroup.org/licenses.               *
 * If you do not have access to either file, you may request a copy from     *
 * help@hdfgroup.org.                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * This file contains function prototypes for each exported function in the
 * H5P module.
 */
#ifndef H5Ppublic_H
#define H5Ppublic_H

/* System headers needed by this file */

/* Public headers needed by this file */
#include "H5public.h"
#include "H5ACpublic.h"
#include "H5Dpublic.h"
#include "H5Fpublic.h"
#include "H5FDpublic.h"
#include "H5Ipublic.h"
#include "H5Lpublic.h"
#include "H5Opublic.h"
#include "H5MMpublic.h"
#include "H5Tpublic.h"
#include "H5Zpublic.h"

/*****************/
/* Public Macros */
/*****************/

/* When this header is included from a private HDF5 header, don't make calls to H5open() */
#undef H5OPEN
#ifndef H5private_H
#define H5OPEN H5open(),
#else /* H5private_H */
#define H5OPEN
#endif /* H5private_H */

/*
 * The library's property list classes
 */

#define H5P_ROOT             (H5OPEN H5P_CLS_ROOT_ID_g)
#define H5P_OBJECT_CREATE    (H5OPEN H5P_CLS_OBJECT_CREATE_ID_g)
#define H5P_FILE_CREATE      (H5OPEN H5P_CLS_FILE_CREATE_ID_g)
#define H5P_FILE_ACCESS      (H5OPEN H5P_CLS_FILE_ACCESS_ID_g)
#define H5P_DATASET_CREATE   (H5OPEN H5P_CLS_DATASET_CREATE_ID_g)
#define H5P_DATASET_ACCESS   (H5OPEN H5P_CLS_DATASET_ACCESS_ID_g)
#define H5P_DATASET_XFER     (H5OPEN H5P_CLS_DATASET_XFER_ID_g)
#define H5P_FILE_MOUNT       (H5OPEN H5P_CLS_FILE_MOUNT_ID_g)
#define H5P_GROUP_CREATE     (H5OPEN H5P_CLS_GROUP_CREATE_ID_g)
#define H5P_GROUP_ACCESS     (H5OPEN H5P_CLS_GROUP_ACCESS_ID_g)
#define H5P_DATATYPE_CREATE  (H5OPEN H5P_CLS_DATATYPE_CREATE_ID_g)
#define H5P_DATATYPE_ACCESS  (H5OPEN H5P_CLS_DATATYPE_ACCESS_ID_g)
#define H5P_MAP_CREATE       (H5OPEN H5P_CLS_MAP_CREATE_ID_g)
#define H5P_MAP_ACCESS       (H5OPEN H5P_CLS_MAP_ACCESS_ID_g)
#define H5P_STRING_CREATE    (H5OPEN H5P_CLS_STRING_CREATE_ID_g)
#define H5P_ATTRIBUTE_CREATE (H5OPEN H5P_CLS_ATTRIBUTE_CREATE_ID_g)
#define H5P_ATTRIBUTE_ACCESS (H5OPEN H5P_CLS_ATTRIBUTE_ACCESS_ID_g)
#define H5P_OBJECT_COPY      (H5OPEN H5P_CLS_OBJECT_COPY_ID_g)
#define H5P_LINK_CREATE      (H5OPEN H5P_CLS_LINK_CREATE_ID_g)
#define H5P_LINK_ACCESS      (H5OPEN H5P_CLS_LINK_ACCESS_ID_g)
#define H5P_VOL_INITIALIZE   (H5OPEN H5P_CLS_VOL_INITIALIZE_ID_g)
#define H5P_REFERENCE_ACCESS (H5OPEN H5P_CLS_REFERENCE_ACCESS_ID_g)

/*
 * The library's default property lists
 */
#define H5P_FILE_CREATE_DEFAULT      (H5OPEN H5P_LST_FILE_CREATE_ID_g)
#define H5P_FILE_ACCESS_DEFAULT      (H5OPEN H5P_LST_FILE_ACCESS_ID_g)
#define H5P_DATASET_CREATE_DEFAULT   (H5OPEN H5P_LST_DATASET_CREATE_ID_g)
#define H5P_DATASET_ACCESS_DEFAULT   (H5OPEN H5P_LST_DATASET_ACCESS_ID_g)
#define H5P_DATASET_XFER_DEFAULT     (H5OPEN H5P_LST_DATASET_XFER_ID_g)
#define H5P_FILE_MOUNT_DEFAULT       (H5OPEN H5P_LST_FILE_MOUNT_ID_g)
#define H5P_GROUP_CREATE_DEFAULT     (H5OPEN H5P_LST_GROUP_CREATE_ID_g)
#define H5P_GROUP_ACCESS_DEFAULT     (H5OPEN H5P_LST_GROUP_ACCESS_ID_g)
#define H5P_DATATYPE_CREATE_DEFAULT  (H5OPEN H5P_LST_DATATYPE_CREATE_ID_g)
#define H5P_DATATYPE_ACCESS_DEFAULT  (H5OPEN H5P_LST_DATATYPE_ACCESS_ID_g)
#define H5P_MAP_CREATE_DEFAULT       (H5OPEN H5P_LST_MAP_CREATE_ID_g)
#define H5P_MAP_ACCESS_DEFAULT       (H5OPEN H5P_LST_MAP_ACCESS_ID_g)
#define H5P_ATTRIBUTE_CREATE_DEFAULT (H5OPEN H5P_LST_ATTRIBUTE_CREATE_ID_g)
#define H5P_ATTRIBUTE_ACCESS_DEFAULT (H5OPEN H5P_LST_ATTRIBUTE_ACCESS_ID_g)
#define H5P_OBJECT_COPY_DEFAULT      (H5OPEN H5P_LST_OBJECT_COPY_ID_g)
#define H5P_LINK_CREATE_DEFAULT      (H5OPEN H5P_LST_LINK_CREATE_ID_g)
#define H5P_LINK_ACCESS_DEFAULT      (H5OPEN H5P_LST_LINK_ACCESS_ID_g)
#define H5P_VOL_INITIALIZE_DEFAULT   (H5OPEN H5P_LST_VOL_INITIALIZE_ID_g)
#define H5P_REFERENCE_ACCESS_DEFAULT (H5OPEN H5P_LST_REFERENCE_ACCESS_ID_g)

/* Common creation order flags (for links in groups and attributes on objects) */
#define H5P_CRT_ORDER_TRACKED 0x0001
#define H5P_CRT_ORDER_INDEXED 0x0002

/* Default value for all property list classes */
#define H5P_DEFAULT (hid_t)0

#ifdef __cplusplus
extern "C" {
#endif

/*******************/
/* Public Typedefs */
/*******************/

/* Define property list class callback function pointer types */
//! <!-- [H5P_cls_create_func_t_snip] -->
typedef herr_t (*H5P_cls_create_func_t)(hid_t prop_id, void *create_data);
//! <!-- [H5P_cls_create_func_t_snip] -->

//! <!-- [H5P_cls_copy_func_t_snip] -->
typedef herr_t (*H5P_cls_copy_func_t)(hid_t new_prop_id, hid_t old_prop_id, void *copy_data);
//! <!-- [H5P_cls_copy_func_t_snip] -->

//! <!-- [H5P_cls_close_func_t_snip] -->
typedef herr_t (*H5P_cls_close_func_t)(hid_t prop_id, void *close_data);
//! <!-- [H5P_cls_close_func_t_snip] -->

/* Define property list callback function pointer types */
//! <!-- [H5P_prp_cb1_t_snip] -->
/**
 * \brief Callback function for H5Pregister2(),H5Pregister1(),H5Pinsert2(),H5Pinsert1()
 *
 * \param[in]     name  The name of the property
 * \param[in]     size  The size of the property in bytes
 * \param[in,out] value The value for the property
 * \return \herr_t
 *
 * \details The H5P_prp_cb1_t() describes the parameters used by the
 *          property create,copy and close callback functions.
 */
typedef herr_t (*H5P_prp_cb1_t)(const char *name, size_t size, void *value);
//! <!-- [H5P_prp_cb1_t_snip] -->

//! <!-- [H5P_prp_cb2_t_snip] -->
/**
 * \brief Callback function for H5Pregister2(),H5Pregister1(),H5Pinsert2(),H5Pinsert1()
 *
 * \plist_id{prop_id}
 * \param[in]     name  The name of the property
 * \param[in]     size  The size of the property in bytes
 * \param[in]     value The value for the property
 * \return \herr_t
 *
 * \details The H5P_prp_cb2_t() describes the parameters used by the
 *          property set ,copy and delete callback functions.
 */
typedef herr_t (*H5P_prp_cb2_t)(hid_t prop_id, const char *name, size_t size, void *value);
//! <!-- [H5P_prp_cb2_t_snip] -->

typedef H5P_prp_cb1_t H5P_prp_create_func_t;
typedef H5P_prp_cb2_t H5P_prp_set_func_t;
typedef H5P_prp_cb2_t H5P_prp_get_func_t;
typedef herr_t (*H5P_prp_encode_func_t)(const void *value, void **buf, size_t *size);
typedef herr_t (*H5P_prp_decode_func_t)(const void **buf, void *value);
typedef H5P_prp_cb2_t H5P_prp_delete_func_t;
typedef H5P_prp_cb1_t H5P_prp_copy_func_t;

//! <!-- [H5P_prp_compare_func_t_snip] -->
typedef int (*H5P_prp_compare_func_t)(const void *value1, const void *value2, size_t size);
//! <!-- [H5P_prp_compare_func_t_snip] -->

typedef H5P_prp_cb1_t H5P_prp_close_func_t;

/* Define property list iteration function type */
//! <!-- [H5P_iterate_t_snip] -->
typedef herr_t (*H5P_iterate_t)(hid_t id, const char *name, void *iter_data);
//! <!-- [H5P_iterate_t_snip] -->

//! <!--[H5D_mpio_actual_chunk_opt_mode_t_snip] -->
/**
 * Actual IO mode property
 *
 * \details The default value, #H5D_MPIO_NO_CHUNK_OPTIMIZATION, is used for all
 *          I/O operations that do not use chunk optimizations, including
 *          non-collective I/O and contiguous collective I/O.
 */
typedef enum H5D_mpio_actual_chunk_opt_mode_t {
    H5D_MPIO_NO_CHUNK_OPTIMIZATION = 0,
    /**< No chunk optimization was performed. Either no collective I/O was
        attempted or the dataset wasn't chunked. */
    H5D_MPIO_LINK_CHUNK,
    /**< Collective I/O is performed on all chunks simultaneously. */
    H5D_MPIO_MULTI_CHUNK
    /**< Each chunk was individually assigned collective or independent I/O based
         on what fraction of processes access the chunk. If the fraction is greater
         than the multi chunk ratio threshold, collective I/O is performed on that
         chunk. The multi chunk ratio threshold can be set using
         H5Pset_dxpl_mpio_chunk_opt_ratio(). The default value is 60%. */
} H5D_mpio_actual_chunk_opt_mode_t;
//! <!--[H5D_mpio_actual_chunk_opt_mode_t_snip] -->

//! <!-- [H5D_mpio_actual_io_mode_t_snip] -->
/**
 * The following values are conveniently defined as a bit field so that
 * we can switch from the default to independent or collective and then to
 * mixed without having to check the original value.
 */
typedef enum H5D_mpio_actual_io_mode_t {
    H5D_MPIO_NO_COLLECTIVE = 0x0,
    /**< No collective I/O was performed. Collective I/O was not requested or
         collective I/O isn't possible on this dataset */
    H5D_MPIO_CHUNK_INDEPENDENT = 0x1,
    /**< HDF5 performed one the chunk collective optimization schemes and each
         chunk was accessed independently */
    H5D_MPIO_CHUNK_COLLECTIVE = 0x2,
    /**< HDF5 performed one the chunk collective optimization schemes and each
         chunk was accessed collectively */
    H5D_MPIO_CHUNK_MIXED = 0x1 | 0x2,
    /**< HDF5 performed one the chunk collective optimization schemes and some
         chunks were accessed independently, some collectively. */
    /** \internal The contiguous case is separate from the bit field. */
    H5D_MPIO_CONTIGUOUS_COLLECTIVE = 0x4
    /**< Collective I/O was performed on a contiguous dataset */
} H5D_mpio_actual_io_mode_t;
//! <!-- [H5D_mpio_actual_io_mode_t_snip] -->

//! <!-- [H5D_mpio_no_collective_cause_t_snip] -->
/**
 * Broken collective IO property
 */
typedef enum H5D_mpio_no_collective_cause_t {
    H5D_MPIO_COLLECTIVE = 0x00,
    /**< Collective I/O was performed successfully */
    H5D_MPIO_SET_INDEPENDENT = 0x01,
    /**< Collective I/O was not performed because independent I/O was requested */
    H5D_MPIO_DATATYPE_CONVERSION = 0x02,
    /**< Collective I/O was not performed because datatype conversions were required */
    H5D_MPIO_DATA_TRANSFORMS = 0x04,
    /**< Collective I/O was not performed because data transforms needed to be applied */
    H5D_MPIO_MPI_OPT_TYPES_ENV_VAR_DISABLED = 0x08,
    /**< \todo FIXME! */
    H5D_MPIO_NOT_SIMPLE_OR_SCALAR_DATASPACES = 0x10,
    /**< Collective I/O was not performed because one of the dataspaces was neither simple nor scalar */
    H5D_MPIO_NOT_CONTIGUOUS_OR_CHUNKED_DATASET = 0x20,
    /**< Collective I/O was not performed because the dataset was neither contiguous nor chunked */
    H5D_MPIO_PARALLEL_FILTERED_WRITES_DISABLED = 0x40,
    /**< \todo FIXME! */
    H5D_MPIO_ERROR_WHILE_CHECKING_COLLECTIVE_POSSIBLE = 0x80,
    /**< \todo FIXME! */
    H5D_MPIO_NO_COLLECTIVE_MAX_CAUSE = 0x100
    /**< Sentinel */
} H5D_mpio_no_collective_cause_t;
//! <!-- [H5D_mpio_no_collective_cause_t_snip] -->

/********************/
/* Public Variables */
/********************/

/* Property list class IDs */
/* (Internal to library, do not use!  Use macros above) */
H5_DLLVAR hid_t H5P_CLS_ROOT_ID_g;
H5_DLLVAR hid_t H5P_CLS_OBJECT_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_FILE_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_FILE_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_DATASET_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_DATASET_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_DATASET_XFER_ID_g;
H5_DLLVAR hid_t H5P_CLS_FILE_MOUNT_ID_g;
H5_DLLVAR hid_t H5P_CLS_GROUP_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_GROUP_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_DATATYPE_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_DATATYPE_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_MAP_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_MAP_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_STRING_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_ATTRIBUTE_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_ATTRIBUTE_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_OBJECT_COPY_ID_g;
H5_DLLVAR hid_t H5P_CLS_LINK_CREATE_ID_g;
H5_DLLVAR hid_t H5P_CLS_LINK_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_CLS_VOL_INITIALIZE_ID_g;
H5_DLLVAR hid_t H5P_CLS_REFERENCE_ACCESS_ID_g;

/* Default roperty list IDs */
/* (Internal to library, do not use!  Use macros above) */
H5_DLLVAR hid_t H5P_LST_FILE_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_FILE_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_DATASET_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_DATASET_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_DATASET_XFER_ID_g;
H5_DLLVAR hid_t H5P_LST_FILE_MOUNT_ID_g;
H5_DLLVAR hid_t H5P_LST_GROUP_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_GROUP_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_DATATYPE_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_DATATYPE_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_MAP_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_MAP_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_ATTRIBUTE_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_ATTRIBUTE_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_OBJECT_COPY_ID_g;
H5_DLLVAR hid_t H5P_LST_LINK_CREATE_ID_g;
H5_DLLVAR hid_t H5P_LST_LINK_ACCESS_ID_g;
H5_DLLVAR hid_t H5P_LST_VOL_INITIALIZE_ID_g;
H5_DLLVAR hid_t H5P_LST_REFERENCE_ACCESS_ID_g;

/*********************/
/* Public Prototypes */
/*********************/

/* Generic property list routines */

/**
 * \ingroup GPLO
 *
 * \brief Terminates access to a property list
 *
 * \plist_id
 *
 * \return \herr_t
 *
 * \details H5Pclose() terminates access to a property list. All property
 *          lists should be closed when the application is finished
 *          accessing them. This frees resources used by the property
 *          list.
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pclose(hid_t plist_id);
/**
 * \ingroup GPLOA
 *
 * \brief Closes an existing property list class
 *
 * \plistcls_id{plist_id}
 *
 * \return \herr_t
 *
 * \details H5Pclose_class() removes a property list class from the library.
 *          Existing property lists of this class will continue to exist,
 *          but new ones are not able to be created.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Pclose_class(hid_t plist_id);
/**
 * \ingroup GPLO
 *
 * \brief Copies an existing property list to create a new property list
 *
 * \plist_id
 *
 * \return \hid_t{property list}
 *
 * \details H5Pcopy() copies an existing property list to create a new
 *          property list. The new property list has the same properties
 *          and values as the original property list.
 *
 * \since 1.0.0
 *
 */
H5_DLL hid_t H5Pcopy(hid_t plist_id);
/**
 * \ingroup GPLOA
 *
 * \brief Copies a property from one list or class to another
 *
 * \param[in] dst_id Identifier of the destination property list or class
 * \param[in] src_id Identifier of the source property list or class
 * \param[in] name Name of the property to copy
 *
 * \return \herr_t
 *
 * \details H5Pcopy_prop() copies a property from one property list or
 *          class to another.
 *
 *          If a property is copied from one class to another, all the
 *          property information will be first deleted from the destination
 *          class and then the property information will be copied from the
 *          source class into the destination class.
 *
 *          If a property is copied from one list to another, the property
 *          will be first deleted from the destination list (generating a
 *          call to the close callback for the property, if one exists)
 *          and then the property is copied from the source list to the
 *          destination list (generating a call to the copy callback for
 *          the property, if one exists).
 *
 *          If the property does not exist in the class or list, this
 *          call is equivalent to calling H5Pregister() or H5Pinsert() (for
 *          a class or list, as appropriate) and the create callback will
 *          be called in the case of the property being copied into a list
 *          (if such a callback exists for the property).
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pcopy_prop(hid_t dst_id, hid_t src_id, const char *name);
/**
 * \ingroup GPLO
 *
 * \brief Creates a new property list as an instance of a property list class
 *
 * \plistcls_id{cls_id}
 *
 * \return \hid_t{property list}
 *
 * \details H5Pcreate() creates a new property list as an instance of
 *          some property list class. The new property list is initialized
 *          with default values for the specified class. The classes are as
 *          follows:
 *
 * <table>
 *   <tr>
 *     <th>Class Identifier</th>
 *     <th>Class Name</th>
 *     <th>Comments</th>
 *   </tr>
 *   <tr>
 *     <td>#H5P_ATTRIBUTE_CREATE</td>
 *     <td>attribute create</td>
 *     <td>Properties for attribute creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_DATASET_ACCESS</td>
 *     <td>dataset access</td>
 *     <td>Properties for dataset access</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_DATASET_CREATE</td>
 *     <td>dataset create</td>
 *     <td>Properties for dataset creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_DATASET_XFER</td>
 *     <td>data transfer</td>
 *     <td>Properties for raw data transfer</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_DATATYPE_ACCESS</td>
 *     <td>datatype access</td>
 *     <td>Properties for datatype access</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_DATATYPE_CREATE</td>
 *     <td>datatype create</td>
 *     <td>Properties for datatype creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_FILE_ACCESS</td>
 *     <td>file access</td>
 *     <td>Properties for file access</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_FILE_CREATE</td>
 *     <td>file create</td>
 *     <td>Properties for file creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_FILE_MOUNT</td>
 *     <td>file mount</td>
 *     <td>Properties for file mounting</td>
 *   </tr>
 *   <tr valign="top">
 *     <td>#H5P_GROUP_ACCESS</td>
 *     <td>group access</td>
 *     <td>Properties for group access</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_GROUP_CREATE</td>
 *     <td>group create</td>
 *     <td>Properties for group creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_LINK_ACCESS</td>
 *     <td>link access</td>
 *     <td>Properties governing link traversal when accessing objects</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_LINK_CREATE</td>
 *     <td>link create</td>
 *     <td>Properties governing link creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_OBJECT_COPY</td>
 *     <td>object copy</td>
 *     <td>Properties governing the object copying process</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_OBJECT_CREATE</td>
 *     <td>object create</td>
 *     <td>Properties for object creation</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_STRING_CREATE</td>
 *     <td>string create</td>
 *     <td>Properties for character encoding when encoding strings or
 *       object names</td>
 *   </tr>
 *   <tr>
 *     <td>#H5P_VOL_INITIALIZE</td>
 *     <td>vol initialize</td>
 *     <td>Properties for VOL initialization</td>
 *   </tr>
 * </table>
 *
 * This property list must eventually be closed with H5Pclose();
 * otherwise, errors are likely to occur.
 *
 * \version 1.12.0 The #H5P_VOL_INITIALIZE property list class was added
 * \version 1.8.15 For each class, the class name returned by
 *                 H5Pget_class_name() was added.
 *                 The list of possible Fortran values was updated.
 * \version 1.8.0 The following property list classes were added at this
 *                release: #H5P_DATASET_ACCESS, #H5P_GROUP_CREATE,
 *                #H5P_GROUP_ACCESS, #H5P_DATATYPE_CREATE,
 *                #H5P_DATATYPE_ACCESS, #H5P_ATTRIBUTE_CREATE
 *
 * \since 1.0.0
 *
 */
H5_DLL hid_t H5Pcreate(hid_t cls_id);
/**
 * \ingroup GPLOA
 *
 * \brief Creates a new property list class
 *
 * \plistcls_id{parent}
 * \param[in] name        Name of property list class to register
 * \param[in] create      Callback routine called when a property list is
 *                        created
 * \param[in] create_data Pointer to user-defined class create data, to be
 *                        passed along to class create callback
 * \param[in] copy        Callback routine called when a property list is
 *                        copied
 * \param[in] copy_data   Pointer to user-defined class copy data, to be
 *                        passed along to class copy callback
 * \param[in] close       Callback routine called when a property list is
 *                        being closed
 * \param[in] close_data  Pointer to user-defined class close data, to be
 *                        passed along to class close callback
 *
 * \return \hid_t{property list class}
 *
 * \details H5Pcreate_class() registers a new property list class with the
 *          library. The new property list class can inherit from an
 *          existing property list class, \p parent, or may be derived
 *          from the default “empty” class, NULL. New classes with
 *          inherited properties from existing classes may not remove
 *          those existing properties, only add or remove their own class
 *          properties. Property list classes defined and supported in the
 *          HDF5 library distribution are listed and briefly described in
 *          H5Pcreate(). The \p create routine is called when a new property
 *          list of this class is being created. The #H5P_cls_create_func_t
 *          callback function is defined as follows:
 *
 *          \snippet this H5P_cls_create_func_t_snip
 *
 *          The parameters to this callback function are defined as follows:
 *          <table>
 *            <tr>
 *              <td>\ref hid_t \c prop_id</td>
 *              <td>IN: The identifier of the property list being created</td>
 *            </tr>
 *            <tr>
 *              <td>\Code{void * create_data}</td>
 *              <td>IN: User pointer to any class creation data required</td>
 *            </tr>
 *          </table>
 *
 *          The \p create routine is called after any registered
 *          \p create function is called for each property value. If the
 *          \p create routine returns a negative value, the new list is not
 *          returned to the user and the property list creation routine returns
 *          an error value.
 *
 *          The \p copy routine is called when an existing property
 *          list of this class is copied. The #H5P_cls_copy_func_t callback
 *          function is defined as follows:
 *          \snippet this H5P_cls_copy_func_t_snip
 *
 *          The parameters to this callback function are defined as follows:
 *          <table>
 *            <tr>
 *              <td>\ref hid_t \c prop_id</td>
 *              <td>IN: The identifier of the property list created by copying</td>
 *            </tr>
 *            <tr>
 *              <td>\Code{void * copy_data}</td>
 *              <td>IN: User pointer to any class copy data required</td>
 *            </tr>
 *          </table>
 *
 *          The \p copy routine is called after any registered \p copy function
 *          is called for each property value. If the \p copy routine returns a
 *          negative value, the new list is not returned to the user and the
 *          property list \p copy routine returns an error value.
 *
 *           The \p close routine is called when a property list of this class
 *           is being closed. The #H5P_cls_close_func_t callback function is
 *           defined as follows:
 *           \snippet this H5P_cls_close_func_t_snip
 *
 *           The parameters to this callback function are defined as follows:
 *           <table>
 *            <tr>
 *              <td>\ref hid_t \c prop_id</td>
 *              <td>IN: The identifier of the property list being closed</td>
 *            </tr>
 *            <tr>
 *              <td>\Code{void * close_data}</td>
 *              <td>IN: User pointer to any class close data required</td>
 *            </tr>
 *          </table>
 *
 *          The \p close routine is called before any registered \p close
 *          function is called for each property value. If the \p close routine
 *          returns a negative value, the property list close routine returns
 *          an error value but the property list is still closed.
 *
 *          H5Pclose_class() can be used to release the property list class
 *          identifier returned by this function so that resources leaks will
 *          not develop.
 *
 * \since 1.4.0
 *
 */
H5_DLL hid_t H5Pcreate_class(hid_t parent, const char *name, H5P_cls_create_func_t create, void *create_data,
                             H5P_cls_copy_func_t copy, void *copy_data, H5P_cls_close_func_t close,
                             void *close_data);
/**
 * \ingroup GPLO
 *
 * \brief Decodes property list received in a binary object buffer and
 *        returns a new property list identifier
 *
 * \param[in] buf Buffer holding the encoded property list
 *
 * \return \hid_tv{object}
 *
 * \details Given a binary property list description in a buffer, H5Pdecode()
 *          reconstructs the HDF5 property list and returns an identifier
 *          for the new property list. The binary description of the property
 *          list is encoded by H5Pencode().
 *
 *          The user is responsible for passing in the correct buffer.
 *
 *          The property list identifier returned by this function should be
 *          released with H5Pclose() when the identifier is no longer needed
 *          so that resource leaks will not develop.
 *
 * \note Some properties cannot be encoded and therefore will not be available
 *       in the decoded property list. These properties are discussed in
 *       H5Pencode().
 *
 * \since 1.10.0
 *
 */
H5_DLL hid_t H5Pdecode(const void *buf);
/**
 * \ingroup GPLO
 *
 * \brief Encodes the property values in a property list into a binary
 *        buffer
 *
 * \plist_id
 * \param[out] buf    Buffer into which the property list will be encoded.
 *                    If the provided buffer is NULL, the size of the
 *                    buffer required is returned through \p nalloc; the
 *                    function does nothing more.
 * \param[out] nalloc The size of the required buffer
 * \fapl_id
 *
 * \return \herr_t
 *
 * \details H5Pencode2() encodes the property list \p plist_id into the
 *          binary buffer \p buf, according to the file format setting
 *          specified by the file access property list \p fapl_id.
 *
 *          If the required buffer size is unknown, \p buf can be passed
 *          in as NULL and the function will set the required buffer size
 *          in \p nalloc. The buffer can then be created and the property
 *          list encoded with a subsequent H5Pencode2() call.
 *
 *          If the buffer passed in is not big enough to hold the encoded
 *          properties, the H5Pencode2() call can be expected to fail with
 *          a segmentation fault.
 *
 *          The file access property list \p fapl_id is used to
 *          control the encoding via the \a libver_bounds property
 *          (see H5Pset_libver_bounds()). If the \a libver_bounds
 *          property is missing, H5Pencode2() proceeds as if the \a
 *          libver_bounds property were set to (#H5F_LIBVER_EARLIEST,
 *          #H5F_LIBVER_LATEST). (Functionally, H5Pencode1() is identical to
 *          H5Pencode2() with \a libver_bounds set to (#H5F_LIBVER_EARLIEST,
 *          #H5F_LIBVER_LATEST).)
 *          Properties that do not have encode callbacks will be skipped.
 *          There is currently no mechanism to register an encode callback for
 *          a user-defined property, so user-defined properties cannot currently
 *          be encoded.
 *
 *          Some properties cannot be encoded, particularly properties that are
 *          reliant on local context.
 *
 *      \b Motivation:
 *       This function was introduced in HDF5-1.12 as part of the \a H5Sencode
 *       format change to enable 64-bit selection encodings and a dataspace
 *       selection that is tied to a file.
 *
 * \since 1.12.0
 *
 */
H5_DLL herr_t H5Pencode2(hid_t plist_id, void *buf, size_t *nalloc, hid_t fapl_id);
/**
 * \ingroup GPLOA
 *
 * \brief Compares two property lists or classes for equality
 *
 * \param[in] id1 First property object to be compared
 * \param[in] id2 Second property object to be compared
 *
 * \return \htri_t
 *
 * \details H5Pequal() compares two property lists or classes to determine
 *          whether they are equal to one another.
 *
 *          Either both \p id1 and \p id2 must be property lists or both
 *          must be classes; comparing a list to a class is an error.
 *
 * \since 1.4.0
 *
 */
H5_DLL htri_t H5Pequal(hid_t id1, hid_t id2);
/**
 * \ingroup GPLOA
 *
 * \brief Queries whether a property name exists in a property list or
 *       class
 *
 * \param[in] plist_id   Identifier for the property list or class to query
 * \param[in] name       Name of property to check for
 *
 * \return \htri_t
 *
 * \details  H5Pexist() determines whether a property exists within a
 *           property list or class.
 *
 * \since 1.4.0
 *
 */
H5_DLL htri_t H5Pexist(hid_t plist_id, const char *name);
/**
 * \ingroup GPLOA
 *
 * \brief Queries the value of a property
 *
 * \plist_id
 * \param[in]  name  Name of property to query
 * \param[out] value Pointer to a location to which to copy the value of
 *                   the property
 *
 * \return \herr_t
 *
 * \details H5Pget() retrieves a copy of the value for a property in a
 *          property list. If there is a \p get callback routine registered
 *          for this property, the copy of the value of the property will
 *          first be passed to that routine and any changes to the copy of
 *          the value will be used when returning the property value from
 *          this routine.
 *
 *          This routine may be called for zero-sized properties with the
 *          \p value set to NULL. The \p get routine will be called with
 *          a NULL value if the callback exists.
 *
 *          The property name must exist or this routine will fail.
 *
 *          If the \p get callback routine returns an error, \ value will
 *          not be modified.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Pget(hid_t plist_id, const char *name, void *value);
/**
 *\ingroup GPLO
 *
 * \brief Returns the property list class identifier for a property list
 *
 * \plist_id
 *
 * \return \hid_t{property list class}
 *
 * \details H5Pget_class() returns the property list class identifier for
 *          the property list identified by the \p plist_id parameter.
 *
 *          Note that H5Pget_class() returns a value of #hid_t type, an
 *          internal HDF5 identifier, rather than directly returning a
 *          property list class. That identifier can then be used with
 *          either H5Pequal() or H5Pget_class_name() to determine which
 *          predefined HDF5 property list class H5Pget_class() has returned.
 *
 *          A full list of valid predefined property list classes appears
 *          in the description of H5Pcreate().
 *
 *          Determining the HDF5 property list class name with H5Pequal()
 *          requires a series of H5Pequal() calls in an if-else sequence.
 *          An iterative sequence of H5Pequal() calls can compare the
 *          identifier returned by H5Pget_class() to members of the list of
 *          valid property list class names. A pseudo-code snippet might
 *          read as follows:
 *
 *          \code
 *          plist_class_id = H5Pget_class (dsetA_plist);
 *
 *          if H5Pequal (plist_class_id, H5P_OBJECT_CREATE) = TRUE;
 *              [ H5P_OBJECT_CREATE is the property list class    ]
 *              [ returned by H5Pget_class.                        ]
 *
 *          else if H5Pequal (plist_class_id, H5P_DATASET_CREATE) = TRUE;
 *              [ H5P_DATASET_CREATE is the property list class.  ]
 *
 *          else if H5Pequal (plist_class_id, H5P_DATASET_XFER) = TRUE;
 *              [ H5P_DATASET_XFER is the property list class.    ]
 *
 *          .
 *          .   [ Continuing the iteration until a match is found. ]
 *          .
 *          \endcode
 *
 *          H5Pget_class_name() returns the property list class name directly
 *          as a string:
 *
 *          \code
 *          plist_class_id = H5Pget_class (dsetA_plist);
 *          plist_class_name = H5Pget_class_name (plist_class_id)
 *          \endcode
 *
 *          Note that frequent use of H5Pget_class_name() can become a
 *          performance problem in a high-performance environment. The
 *          H5Pequal() approach is generally much faster.
 *
 * \version 1.6.0 Return type changed in this release.
 * \since 1.0.0
 *
 */
H5_DLL hid_t H5Pget_class(hid_t plist_id);
/**
 * \ingroup GPLOA
 *
 * \brief Retrieves the name of a class
 *
 * \plistcls_id{pclass_id}
 *
 * \return Returns a pointer to an allocated string containing the class
 *         name if successful, and NULL if not successful.
 *
 * \details H5Pget_class_name() retrieves the name of a generic property
 *          list class. The pointer to the name must be freed by the user
 *          with a call to H5free_memory() after each successful call.
 *
 *          <table>
 *           <tr>
 *            <th>Class Name (class identifier) Returned</th>
 *            <th>Property List Class</th>
 *            <th>Expanded Name of the Property List Class</th>
 *            <th>The Class Identifier Used with H5Pcreate</th>
 *            <th>Comments</th>
 *           </tr>
 *           <tr>
 *            <td>attribute create</td>
 *            <td>acpl</td>
 *            <td>Attribute Creation Property List</td>
 *            <td>H5P_ATTRIBUTE_CREATE</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>dataset access</td>
 *            <td>dapl</td>
 *            <td>Dataset Access Property List</td>
 *            <td>H5P_DATASET_ACCESS</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>dataset create</td>
 *            <td>dcpl</td>
 *            <td>Dataset Creation Property List</td>
 *            <td>H5P_DATASET_CREATE</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>data transfer</td>
 *            <td>dxpl</td>
 *            <td>Data Transfer Property List</td>
 *            <td>H5P_DATASET_XFER</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>datatype access</td>
 *            <td> </td>
 *            <td> </td>
 *            <td>H5P_DATATYPE_ACCESS</td>
 *            <td>This class can be created, but there are no properties
 *                in the class currently.
 *            </td>
 *           </tr>
 *           <tr>
 *            <td>datatype create</td>
 *            <td> </td>
 *            <td> </td>
 *            <td>H5P_DATATYPE_CREATE</td>
 *            <td>This class can be created, but there
 *                are no properties in the class currently.</td>
 *           </tr>
 *           <tr>
 *            <td>file access</td>
 *            <td>fapl</td>
 *            <td>File Access Property List</td>
 *            <td>H5P_FILE_ACCESS</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>file create</td>
 *            <td>fcpl</td>
 *            <td>File Creation Property List</td>
 *            <td>H5P_FILE_CREATE</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>file mount</td>
 *            <td>fmpl</td>
 *            <td>File Mount Property List</td>
 *            <td>H5P_FILE_MOUNT</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>group access</td>
 *            <td> </td>
 *            <td> </td>
 *            <td>H5P_GROUP_ACCESS</td>
 *            <td>This class can be created, but there
 *                are no properties in the class currently.</td>
 *           </tr>
 *           <tr>
 *            <td>group create</td>
 *            <td>gcpl</td>
 *            <td>Group Creation Property List</td>
 *            <td>H5P_GROUP_CREATE</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *             <td>link access</td>
 *             <td>lapl</td>
 *             <td>Link Access Property List</td>
 *             <td>H5P_LINK_ACCESS</td>
 *             <td> </td>
 *           </tr>
 *           <tr>
 *            <td>link create</td>
 *            <td>lcpl</td>
 *            <td>Link Creation Property List</td>
 *            <td>H5P_LINK_CREATE</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>object copy</td>
 *            <td>ocpypl</td>
 *            <td>Object Copy Property List</td>
 *            <td>H5P_OBJECT_COPY</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>object create</td>
 *            <td>ocpl</td>
 *            <td>Object Creation Property List</td>
 *            <td>H5P_OBJECT_CREATE</td>
 *            <td> </td>
 *           </tr>
 *           <tr>
 *            <td>string create</td>
 *            <td>strcpl</td>
 *            <td>String Creation Property List</td>
 *            <td>H5P_STRING_CREATE</td>
 *            <td> </td>
 *           </tr>
 *          </table>
 *
 * \since 1.4.0
 *
 */
H5_DLL char *H5Pget_class_name(hid_t pclass_id);
/**
 * \ingroup GPLOA
 *
 * \brief Retrieves the parent class of a property class
 *
 * \plistcls_id{pclass_id}
 *
 * \return \hid_t{parent class object}
 *
 * \details H5Pget_class_parent() retrieves an identifier for the parent
 *          class of a property class.
 *
 * \since 1.4.0
 *
 */
H5_DLL hid_t H5Pget_class_parent(hid_t pclass_id);
/**
 * \ingroup GPLOA
 *
 * \brief  Queries the number of properties in a property list or class
 *
 * \param[in]  id     Identifier for property object to query
 * \param[out] nprops Number of properties in object
 *
 * \return \herr_t
 *
 * \details H5Pget_nprops() retrieves the number of properties in a
 *          property list or property list class.
 *
 *          If \p id is a property list identifier, the current number of
 *          properties in the list is returned in \p nprops.
 *
 *          If \p id is a property list class identifier, the number of
 *          registered properties in the class is returned in \p nprops.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Pget_nprops(hid_t id, size_t *nprops);
/**
 * \ingroup GPLOA
 *
 * \brief Queries the size of a property value in bytes
 *
 * \param[in]  id   Identifier of property object to query
 * \param[in]  name Name of property to query
 * \param[out] size Size of property in bytes
 *
 * \return  \herr_t
 *
 * \details H5Pget_size() retrieves the size of a property's value in
 *          bytes. This function operates on both property lists and
 *          property classes.
 *
 *          Zero-sized properties are allowed and return 0.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Pget_size(hid_t id, const char *name, size_t *size);
/**
 * \ingroup GPLOA
 *
 * \brief Registers a temporary property with a property list
 *
 * \plist_id
 * \param[in] name    Name of property to create
 * \param[in] size    Size of property in bytes
 * \param[in] value   Initial value for the property
 * \param[in] set     Callback routine called before a new value is copied
 *                    into the property's value
 * \param[in] get     Callback routine called when a property value is
 *                    retrieved from the property
 * \param[in] prp_del Callback routine called when a property is deleted
 *                    from a property list
 * \param[in] copy    Callback routine called when a property is copied
 *                    from an existing property list
 * \param[in] compare Callback routine called when a property is compared
 *                    with another property list
 * \param[in] close   Callback routine called when a property list is
 *                    being closed and the property value will be disposed
 *                    of
 *
 * \return \herr_t
 *
 * \details H5Pinsert2() creates a new property in a property
 *          list. The property will exist only in this property list and
 *          copies made from it.
 *
 *          The initial property value must be provided in \p value and
 *          the property value will be set accordingly.
 *
 *          The name of the property must not already exist in this list,
 *          or this routine will fail.
 *
 *          The \p set and \p get callback routines may be set to NULL
 *          if they are not needed.
 *
 *          Zero-sized properties are allowed and do not store any data
 *          in the property list. The default value of a zero-size
 *          property may be set to NULL. They may be used to indicate the
 *          presence or absence of a particular piece of information.
 *
 *          The \p set routine is called before a new value is copied
 *          into the property. The #H5P_prp_set_func_t callback function
 *          is defined as follows:
 *          \snippet this H5P_prp_cb2_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *          <table>
 *           <tr>
 *            <td>\ref hid_t \c prop_id</td>
 *            <td>IN: The identifier of the property list being
 *                modified</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being modified</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *             <td>\Code{void * value}</td>
 *             <td>IN: Pointer to new value pointer for the property
 *                 being modified</td>
 *           </tr>
 *          </table>
 *
 *          The \p set routine may modify the value pointer to be set and
 *          those changes will be used when setting the property's value.
 *          If the \p set routine returns a negative value, the new property
 *          value is not copied into the property and the \p  set routine
 *          returns an error value. The \p set routine will be called for
 *          the initial value.
 *
 *          \b Note: The \p set callback function may be useful to range
 *          check the value being set for the property or may perform some
 *          transformation or translation of the value set. The \p get
 *          callback would then reverse the transformation or translation.
 *          A single \p get or \p set callback could handle multiple
 *          properties by performing different actions based on the
 *          property name or other properties in the property list.
 *
 *          The \p get routine is called when a value is retrieved from
 *          a property value. The #H5P_prp_get_func_t callback function
 *          is defined as follows:
 *
 *          \snippet this H5P_prp_cb2_t_snip
 *
 *          The parameters to the above callback function are:
 *
 *          <table>
 *           <tr>
 *            <td>\ref hid_t \c prop_id</td>
 *            <td>IN: The identifier of the property list being queried</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being queried</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t  size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void *  value}</td>
 *            <td>IN: The value of the property being returned</td>
 *           </tr>
 *          </table>
 *
 *          The \p get routine may modify the value to be returned from
 *          the query and those changes will be preserved. If the \p get
 *          routine returns a negative value, the query routine returns
 *          an error value.
 *
 *          The \p prp_del routine is called when a property is being
 *          deleted from a property list. The #H5P_prp_delete_func_t
 *          callback function is defined as follows:
 *
 *          \snippet this H5P_prp_cb2_t_snip
 *
 *          The parameters to the above callback function are:
 *
 *          <table>
 *           <tr>
 *            <td>\ref hid_t \c prop_id</td>
 *            <td>IN: The identifier of the property list the property is
 *                being deleted from</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property in the list</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN: The value for the property being deleted</td>
 *           </tr>
 *          </table>
 *
 *          The \p prp_del routine may modify the value passed in, but the
 *          value is not used by the library when the \p prp_del routine
 *          returns. If the \p prp_del routine returns a negative value,
 *          the property list \p prp_del routine returns an error value but
 *          the property is still deleted.
 *
 *          The \p copy routine is called when a new property list with
 *          this property is being created through a \p copy operation.
 *
 *          The #H5P_prp_copy_func_t callback function is defined as follows:
 *
 *          \snippet this H5P_prp_cb1_t_snip
 *
 *          The parameters to the above callback function are:
 *          <table>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being copied</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN/OUT: The value for the property being copied</td>
 *           </tr>
 *          </table>
 *
 *          The \p copy routine may modify the value to be set and those
 *          changes will be stored as the new value of the property. If the
 *          \p copy routine returns a negative value, the new property value
 *          is not copied into the property and the copy routine returns an
 *          error value.
 *
 *          The \p compare routine is called when a property list with this
 *          property is compared to another property list with the same
 *          property.
 *
 *          The #H5P_prp_compare_func_t callback function is defined as
 *          follows:
 *
 *          \snippet this H5P_prp_compare_func_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\Code{const void * value1}</td>
 *            <td>IN: The value of the first property to compare</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const void * value2}</td>
 *            <td>IN: The value of the second property to compare</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *          </table>
 *
 *          The \p compare routine may not modify the values. The \p compare
 *          routine should return a positive value if \p value1 is greater
 *          than \p value2, a negative value if \p value2 is greater than
 *          \p value1 and zero if \p value1 and \p value2 are equal.
 *
 *          The \p close routine is called when a property list with this
 *          property is being closed.
 *
 *          The #H5P_prp_close_func_t callback function is defined as follows:
 *          \snippet this H5P_prp_cb1_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property in the list</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN: The value for the property being closed</td>
 *           </tr>
 *          </table>
 *
 *          The \p close routine may modify the value passed in, the
 *          value is not used by the library when the close routine
 *          returns. If the \p close routine returns a negative value,
 *          the property list \p close routine returns an error value
 *          but the property list is still closed.
 *
 *          \b Note: There is no \p create callback routine for temporary
 *          property list objects; the initial value is assumed to
 *          have any necessary setup already performed on it.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pinsert2(hid_t plist_id, const char *name, size_t size, void *value, H5P_prp_set_func_t set,
                         H5P_prp_get_func_t get, H5P_prp_delete_func_t prp_del, H5P_prp_copy_func_t copy,
                         H5P_prp_compare_func_t compare, H5P_prp_close_func_t close);
/**
 * \ingroup GPLOA
 *
 * \brief Determines whether a property list is a member of a class
 *
 * \plist_id
 * \plistcls_id{pclass_id}
 *
 * \return \htri_t
 *
 * \details H5Pisa_class() checks to determine whether the property list
 *          \p plist_id is a member of the property list class
 *          \p pclass_id.
 *
 * \see H5Pcreate()
 *
 * \since  1.6.0
 *
 */
H5_DLL htri_t H5Pisa_class(hid_t plist_id, hid_t pclass_id);
/**
 * \ingroup GPLOA
 *
 * \brief Iterates over properties in a property class or list
 *
 * \param[in]     id  Identifier of property object to iterate over
 * \param[in,out] idx Index of the property to begin with
 * \param[in]     iter_func  Function pointer to function to be called
 *                           with each property iterated over
 * \param[in,out] iter_data  Pointer to iteration data from user
 *
 * \return On success: the return value of the last call to \p iter_func if
 *         it was non-zero; zero if all properties have been processed.
 *         On Failure, a negative value
 *
 * \details H5Piterate() iterates over the properties in the property
 *          object specified in \p id, which may be either a property
 *          list or a property class, performing a specified operation
 *          on each property in turn.
 *
 *          For each property in the object, \p iter_func and the
 *          additional information specified below are passed to the
 *          #H5P_iterate_t operator function.
 *
 *          The iteration begins with the \p idx-th property in the
 *          object; the next element to be processed by the operator
 *          is returned in \p idx. If \p idx is NULL, the iterator
 *          starts at the first property; since no stopping point is
 *          returned in this case, the iterator cannot be restarted if
 *          one of the calls to its operator returns non-zero.
 *
 *          The prototype for the #H5P_iterate_t operator is as follows:
 *          \snippet this H5P_iterate_t_snip
 *
 *          The operation receives the property list or class
 *          identifier for the object being iterated over, \p id, the
 *          name of the current property within the object, \p name,
 *          and the pointer to the operator data passed in to H5Piterate(),
 *          \p iter_data. The valid return values from an operator are
 *          as follows:
 *
 *          <table>
 *           <tr>
 *            <td>Zero</td>
 *            <td>Causes the iterator to continue, returning zero when all
 *                properties have been processed</td>
 *           </tr>
 *           <tr>
 *            <td>Positive</td>
 *            <td>Causes the iterator to immediately return that positive
 *                value, indicating short-circuit success. The iterator
 *                can be restarted at the index of the next property</td>
 *           </tr>
 *           <tr>
 *            <td>Negative</td>
 *            <td>Causes the iterator to immediately return that value,
 *                indicating failure. The iterator can be restarted at the
 *                index of the next property</td>
 *           </tr>
 *          </table>
 *          H5Piterate() assumes that the properties in the object
 *          identified by \p id remain unchanged through the iteration.
 *          If the membership changes during the iteration, the function's
 *          behavior is undefined.
 *
 * \since 1.4.0
 *
 */
H5_DLL int H5Piterate(hid_t id, int *idx, H5P_iterate_t iter_func, void *iter_data);
/**
 * \ingroup GPLOA
 *
 * \brief Registers a permanent property with a property list class
 *
 * \plistcls_id{cls_id}
 * \param[in] name       Name of property to register
 * \param[in] size       Size of property in bytes
 * \param[in] def_value  Default value for property in newly created
 *                       property lists
 * \param[in] create     Callback routine called when a property list is
 *                       being created and the property value will be
 *                       initialized
 * \param[in] set        Callback routine called before a new value is
 *                       copied into the property's value
 * \param[in] get        Callback routine called when a property value is
 *                       retrieved from the property
 * \param[in] prp_del    Callback routine called when a property is deleted
 *                       from a property list
 * \param[in] copy       Callback routine called when a property is copied
 *                       from a property list
 * \param[in] compare    Callback routine called when a property is compared
 *                       with another property list
 * \param[in] close      Callback routine called when a property list is
 *                       being closed and the property value will be
 *                       disposed of
 *
 * \return  \herr_t
 *
 * \details H5Pregister2() registers a new property with a property list
 *          class. The \p cls_id identifier can be obtained by calling
 *          H5Pcreate_class(). The property will exist in all property
 *          list objects of \p cl_id created after this routine finishes. The
 *          name of the property must not already exist, or this routine
 *          will fail. The default property value must be provided and all
 *          new property lists created with this property will have the
 *          property value set to the default value. Any of the callback
 *          routines may be set to NULL if they are not needed.
 *
 *          Zero-sized properties are allowed and do not store any data in
 *          the property list. These may be used as flags to indicate the
 *          presence or absence of a particular piece of information. The
 *          default pointer for a zero-sized property may be set to NULL.
 *          The property \p create and \p close callbacks are called for
 *          zero-sized properties, but the \p set and \p get callbacks are
 *          never called.
 *
 *          The \p create routine is called when a new property list with
 *          this property is being created. The #H5P_prp_create_func_t
 *          callback function is defined as follows:
 *
 *          \snippet this H5P_prp_cb1_t_snip
 *
 *          The parameters to this callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being modified</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN/OUT: The default value for the property being created,
 *                which will be passed to H5Pregister2()</td>
 *           </tr>
 *          </table>
 *
 *          The \p create routine may modify the value to be set and those
 *          changes will be stored as the initial value of the property.
 *          If the \p create routine returns a negative value, the new
 *          property value is not copied into the property and the
 *          \p create routine returns an error value.
 *
 *          The \p set routine is called before a new value is copied into
 *          the property. The #H5P_prp_set_func_t callback function is defined
 *          as follows:
 *
 *          \snippet this H5P_prp_cb2_t_snip
 *
 *          The parameters to this callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\ref hid_t \c prop_id</td>
 *            <td>IN: The identifier of the property list being modified</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being modified</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void *value}</td>
 *            <td>IN/OUT: Pointer to new value pointer for the property
 *                being modified</td>
 *           </tr>
 *          </table>
 *
 *          The \p set routine may modify the value pointer to be set and
 *          those changes will be used when setting the property's value.
 *          If the \p set routine returns a negative value, the new property
 *          value is not copied into the property and the \p set routine
 *          returns an error value. The \p set routine will not be called
 *          for the initial value; only the \p create routine will be called.
 *
 *          \b Note: The \p set callback function may be useful to range
 *          check the value being set for the property or may perform some
 *          transformation or translation of the value set. The \p get
 *          callback would then reverse the transformation or translation.
 *          A single \p get or \p set callback could handle multiple
 *          properties by performing different actions based on the property
 *          name or other properties in the property list.
 *
 *          The \p get routine is called when a value is retrieved from a
 *          property value. The #H5P_prp_get_func_t callback function is
 *          defined as follows:
 *
 *          \snippet this H5P_prp_cb2_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\ref hid_t \c prop_id</td>
 *            <td>IN: The identifier of the property list being
 *                queried</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being queried</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN/OUT: The value of the property being returned</td>
 *           </tr>
 *          </table>
 *
 *          The \p get routine may modify the value to be returned from the
 *          query and those changes will be returned to the calling routine.
 *          If the \p set routine returns a negative value, the query
 *          routine returns an error value.
 *
 *          The \p prp_del routine is called when a property is being
 *          deleted from a property list. The #H5P_prp_delete_func_t
 *          callback function is defined as follows:
 *
 *          \snippet this H5P_prp_cb2_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\ref hid_t \c prop_id</td>
 *            <td>IN: The identifier of the property list the property is
 *                being deleted from</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property in the list</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN: The value for the property being deleted</td>
 *           </tr>
 *          </table>
 *
 *          The \p prp_del routine may modify the value passed in, but the
 *          value is not used by the library when the \p prp_del routine
 *          returns. If the \p prp_del routine returns a negative value,
 *          the property list  delete routine returns an error value but
 *          the property is still deleted.
 *
 *          The \p copy routine is called when a new property list with
 *          this property is being created through a \p copy operation.
 *          The #H5P_prp_copy_func_t callback function is defined as follows:
 *
 *          \snippet this H5P_prp_cb1_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property being copied</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN/OUT: The value for the property being copied</td>
 *           </tr>
 *          </table>
 *
 *          The \p copy routine may modify the value to be set and those
 *          changes will be stored as the new value of the property. If
 *          the \p copy routine returns a negative value, the new
 *          property value is not copied into the property and the \p copy
 *          routine returns an error value.
 *
 *          The \p compare routine is called when a property list with this
 *          property is compared to another property list with the same
 *          property. The #H5P_prp_compare_func_t callback function is
 *          defined as follows:
 *
 *          \snippet this H5P_prp_compare_func_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\Code{const void * value1}</td>
 *            <td>IN: The value of the first property to compare</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{const void * value2}</td>
 *            <td>IN: The value of the second property to compare</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *          </table>
 *
 *          The \p compare routine may not modify the values. The \p compare
 *          routine should return a positive value if \p value1 is greater
 *          than \p value2, a negative value if \p value2 is greater than
 *          \p value1 and zero if \p value1 and \p value2 are equal.
 *
 *          The \p close routine is called when a property list with this
 *          property is being closed. The #H5P_prp_close_func_t callback
 *          function is defined as follows:
 *
 *          \snippet this H5P_prp_cb1_t_snip
 *
 *          The parameters to the callback function are defined as follows:
 *
 *          <table>
 *           <tr>
 *            <td>\Code{const char * name}</td>
 *            <td>IN: The name of the property in the list</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{size_t size}</td>
 *            <td>IN: The size of the property in bytes</td>
 *           </tr>
 *           <tr>
 *            <td>\Code{void * value}</td>
 *            <td>IN: The value for the property being closed</td>
 *           </tr>
 *          </table>
 *
 *          The \p close routine may modify the value passed in, but the
 *          value is not used by the library when the \p close routine returns.
 *          If the \p close routine returns a negative value, the property
 *          list close routine returns an error value but the property list is
 *          still closed.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pregister2(hid_t cls_id, const char *name, size_t size, void *def_value,
                           H5P_prp_create_func_t create, H5P_prp_set_func_t set, H5P_prp_get_func_t get,
                           H5P_prp_delete_func_t prp_del, H5P_prp_copy_func_t copy,
                           H5P_prp_compare_func_t compare, H5P_prp_close_func_t close);
/**
 * \ingroup GPLOA
 *
 * \brief Removes a property from a property list
 *
 * \plist_id
 * \param[in] name Name of property to remove
 *
 * \return \herr_t
 *
 * \details H5Premove() removes a property from a property list. Both
 *          properties which were in existence when the property list was
 *          created (i.e. properties registered with H5Pregister()) and
 *          properties added to the list after it was created (i.e. added
 *          with H5Pinsert1() may be removed from a property list.
 *          Properties do not need to be removed from a property list
 *          before the list itself is closed; they will be released
 *          automatically when H5Pclose() is called.
 *
 *          If a \p close callback exists for the removed property, it
 *          will be called before the property is released.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Premove(hid_t plist_id, const char *name);
/**
 * \ingroup GPLOA
 *
 * \brief Sets a property list value
 *
 * \plist_id
 * \param[in] name  Name of property to modify
 * \param[in] value Pointer to value to set the property to
 *
 * \return \herr_t
 *
 * \details H5Pset() sets a new value for a property in a property list.
 *          If there is a \p set callback routine registered for this
 *          property, the \p value will be passed to that routine and any
 *          changes to the \p value will be used when setting the property
 *          value. The information pointed to by the \p value pointer
 *          (possibly modified by the \p set callback) is copied into the
 *          property list value and may be changed by the application
 *          making the H5Pset() call without affecting the property value.
 *
 *          The property name must exist or this routine will fail.
 *
 *          If the \p set callback routine returns an error, the property
 *          value will not be modified.
 *
 *          This routine may not be called for zero-sized properties and
 *          will return an error in that case.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Pset(hid_t plist_id, const char *name, const void *value);
/**
 * \ingroup GPLOA
 *
 * \brief Removes a property from a property list class
 *
 * \plistcls_id{pclass_id}
 * \param[in] name Name of property to remove
 *
 * \return \herr_t
 *
 * \details H5Punregister() removes a property from a property list class.
 *          Future property lists created of that class will not contain
 *          this property; existing property lists containing this property
 *          are not affected.
 *
 * \since 1.4.0
 *
 */
H5_DLL herr_t H5Punregister(hid_t pclass_id, const char *name);

/* Object creation property list (OCPL) routines */

/**
 * \ingroup DCPL
 *
 * \brief Verifies that all required filters are available
 *
 * \plist_id
 *
 * \return \htri_t
 *
 * \details H5Pall_filters_avail() verifies that all of the filters set in
 *         the dataset or group creation property list \p plist_id are
 *         currently available.
 *
 * \version 1.8.5 Function extended to work with group creation property
 *                lists.
 * \since 1.6.0
 *
 */
H5_DLL htri_t H5Pall_filters_avail(hid_t plist_id);
/**
 * \ingroup OCPL
 *
 * \brief Retrieves tracking and indexing settings for attribute creation
 *        order
 *
 * \plist_id
 * \param[out] crt_order_flags Flags specifying whether to track and
 *             index attribute creation order
 *
 * \return \herr_t
 *
 * \details H5Pget_attr_creation_order() retrieves the settings for
 *          tracking and indexing attribute creation order on an object.
 *
 *          \p plist_id is an object creation property list (\p ocpl),
 *          as it can be a dataset or group creation property list
 *          identifier. The term \p ocpl is used when different types
 *          of objects may be involved.
 *
 *          \p crt_order_flags returns flags with the following meanings:
 *
 *          <table>
 *           <tr>
 *            <td>#H5P_CRT_ORDER_TRACKED</td>
 *            <td>Attribute creation order is tracked but not necessarily
 *                indexed.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5P_CRT_ORDER_INDEXED </td>
 *            <td>Attribute creation order is indexed (requires
 *                #H5P_CRT_ORDER_TRACKED).</td>
 *           </tr>
 *          </table>
 *
 *          If \p crt_order_flags is returned with a value of 0 (zero),
 *          attribute creation order is neither tracked nor indexed.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_attr_creation_order(hid_t plist_id, unsigned *crt_order_flags);
/**
 * \ingroup OCPL
 *
 * \brief Retrieves attribute storage phase change thresholds
 *
 * \plist_id
 * \param[out] max_compact Maximum number of attributes to be stored in
 *                         compact storage (Default: 8)
 * \param[out] min_dense   Minimum number of attributes to be stored in
 *                         dense storage (Default: 6)
 *
 * \return \herr_t
 *
 * \details H5Pget_attr_phase_change() retrieves threshold values for
 *          attribute storage on an object. These thresholds determine the
 *          point at which attribute storage changes from compact storage
 *          (i.e., storage in the object header) to dense storage (i.e.,
 *          storage in a heap and indexed with a B-tree).
 *
 *          In the general case, attributes are initially kept in compact
 *          storage. When the number of attributes exceeds \p max_compact,
 *          attribute storage switches to dense storage. If the number of
 *          attributes subsequently falls below \p min_dense, the
 *          attributes are returned to compact storage.
 *
 *          If \p max_compact is set to 0 (zero), dense storage always used.
 *
 *          \p plist_id is an object creation property list (\p ocpl), as it
 *          can be a dataset or group creation property list identifier.
 *          The term \p ocpl is used when different types of objects may be
 *          involved.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_attr_phase_change(hid_t plist_id, unsigned *max_compact, unsigned *min_dense);
/**
 * \ingroup OCPL
 *
 * \brief Returns information about a filter in a pipeline
 *
 * \todo Signature for H5Pget_filter2 is different in H5Pocpl.c than in
 *       H5Ppublic.h
 *
 * \ocpl_id{plist_id}
 * \param[in] idx    Sequence number within the filter pipeline of the filter
 *                   for which information is sought
 * \param[out] flags Bit vector specifying certain general properties of the
 *                   filter
 * \param[in,out] cd_nelmts Number of elements in \p cd_values
 * \param[out]    cd_values Auxiliary data for the filter
 * \param[in]     namelen   Anticipated number of characters in \p name
 * \param[out]    name      Name of the filter
 * \param[out] filter_config Bit field, as described in H5Zget_filter_info()
 *
 * \return Returns a negative value on failure, and the filter identifier
 *         if successful (see #H5Z_filter_t):
 *         - #H5Z_FILTER_DEFLATE     Data compression filter,
 *                                    employing the gzip algorithm
 *         - #H5Z_FILTER_SHUFFLE     Data shuffling filter
 *         - #H5Z_FILTER_FLETCHER32  Error detection filter, employing the
 *                                     Fletcher32 checksum algorithm
 *         - #H5Z_FILTER_SZIP        Data compression filter, employing the
 *                                     SZIP algorithm
 *         - #H5Z_FILTER_NBIT        Data compression filter, employing the
 *                                     N-bit algorithm
 *         - #H5Z_FILTER_SCALEOFFSET Data compression filter, employing the
 *                                     scale-offset algorithm
 *
 * \details H5Pget_filter2() returns information about a filter specified by
 *          its filter number, in a filter pipeline specified by the property
 *          list with which it is associated.
 *
 *          \p plist_id must be a dataset or group creation property list.
 *
 *          \p idx is a value between zero and N-1, as described in
 *          H5Pget_nfilters(). The function will return a negative value if
 *          the filter number is out of range.
 *
 *          The structure of the \p flags argument is discussed in
 *          H5Pset_filter().
 *
 *          On input, \p cd_nelmts indicates the number of entries in the
 *          \p cd_values array, as allocated by the caller; on return,
 *          \p cd_nelmts contains the number of values defined by the filter.
 *
 *          If \p name is a pointer to an array of at least \p namelen bytes,
 *          the filter name will be copied into that array. The name will be
 *          null terminated if \p namelen is large enough. The filter name
 *          returned will be the name appearing in the file, the name
 *          registered for the filter, or an empty string.
 *
 *          \p filter_config is the bit field described in
 *          H5Zget_filter_info().
 *
 * \version 1.8.5 Function extended to work with group creation property
 *                lists.
 * \since 1.8.0
 *
 */
H5_DLL H5Z_filter_t H5Pget_filter2(hid_t plist_id, unsigned idx, unsigned int *flags /*out*/,
                                   size_t *cd_nelmts /*out*/, unsigned cd_values[] /*out*/, size_t namelen,
                                   char name[], unsigned *filter_config /*out*/);
/**
 * \ingroup OCPL
 *
 * \brief Returns information about the specified filter
 *
 * \ocpl_id{plist_id}
 * \param[in]     filter_id     Filter identifier
 * \param[out]    flags         Bit vector specifying certain general
 *                              properties of the filter
 * \param[in,out] cd_nelmts     Number of elements in \p cd_values
 * \param[out]    cd_values[]   Auxiliary data for the filter
 * \param[in]     namelen       Length of filter name and number of
 *                              elements in \p name
 * \param[out]    name[]        Name of filter
 * \param[out]    filter_config Bit field, as described in
 *                              H5Zget_filter_info()
 *
 * \return \herr_t
 *
 * \details H5Pget_filter_by_id2() returns information about the filter
 *          specified in \p filter_id, a filter identifier.
 *
 *          \p plist_id must be a dataset or group creation property list
 *          and \p filter_id must be in the associated filter pipeline.
 *
 *          The \p filter_id and \p flags parameters are used in the same
 *          manner as described in the discussion of H5Pset_filter().
 *
 *          Aside from the fact that they are used for output, the
 *          parameters \p cd_nelmts and \p cd_values[] are used in the same
 *          manner as described in the discussion of H5Pset_filter(). On
 *          input, the \p cd_nelmts parameter indicates the number of
 *          entries in the \p cd_values[] array allocated by the calling
 *          program; on exit it contains the number of values defined by
 *          the filter.
 *
 *          On input, the \p namelen parameter indicates the number of
 *          characters allocated for the filter name by the calling program
 *          in the array \p name[]. On exit \p name[] contains the name of the
 *          filter with one character of the name in each element of the
 *          array.
 *
 *          \p filter_config is the bit field described in
 *          H5Zget_filter_info().
 *
 *          If the filter specified in \p filter_id is not set for the
 *          property list, an error will be returned and
 *          H5Pget_filter_by_id2() will fail.
 *
 * \version 1.8.5 Function extended to work with group creation property
 *                lists.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_filter_by_id2(hid_t plist_id, H5Z_filter_t filter_id, unsigned int *flags /*out*/,
                                   size_t *cd_nelmts /*out*/, unsigned cd_values[] /*out*/, size_t namelen,
                                   char name[] /*out*/, unsigned *filter_config /*out*/);
/**
 * \ingroup OCPL
 *
 * \brief Returns the number of filters in the pipeline
 *
 * \ocpl_id{plist_id}
 *
 * \return  Returns the number of filters in the pipeline if successful;
 *          otherwise returns a negative value.
 *
 * \details H5Pget_nfilters() returns the number of filters defined in the
 *          filter pipeline associated with the property list \p plist_id.
 *
 *          In each pipeline, the filters are numbered from 0 through \Code{N-1},
 *          where \c N is the value returned by this function. During output to
 *          the file, the filters are applied in increasing order; during
 *          input from the file, they are applied in decreasing order.
 *
 *          H5Pget_nfilters() returns the number of filters in the pipeline,
 *          including zero (0) if there are none.
 *
 * \since 1.0.0
 *
 */
H5_DLL int H5Pget_nfilters(hid_t plist_id);
/**
 * \ingroup OCPL
 *
 * \brief Determines whether times associated with an object
 *       are being recorded
 *
 * \plist_id
 * \param[out] track_times Boolean value, 1 (TRUE) or 0 (FALSE),
 *             specifying whether object times are being recorded
 *
 * \return \herr_t
 *
 * \details H5Pget_obj_track_times() queries the object creation property
 *          list, \p plist_id, to determine whether object times are being
 *          recorded.
 *
 *          If \p track_times is returned as 1, times are being recorded;
 *          if \p track_times is returned as 0, times are not being
 *          recorded.
 *
 *          Time data can be retrieved with H5Oget_info(), which will return
 *          it in the #H5O_info_t struct.
 *
 *          If times are not tracked, they will be reported as follows
 *          when queried: 12:00 AM UDT, Jan. 1, 1970
 *
 *          See H5Pset_obj_track_times() for further discussion.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_obj_track_times(hid_t plist_id, hbool_t *track_times);
/**
 * \ingroup OCPL
 *
 * \brief Modifies a filter in the filter pipeline
 *
 * \ocpl_id{plist_id}
 * \param[in] filter      Filter to be modified
 * \param[in] flags       Bit vector specifying certain general properties
 *                        of the filter
 * \param[in] cd_nelmts   Number of elements in \p cd_values
 * \param[in] cd_values[] Auxiliary data for the filter
 *
 * \return \herr_t
 *
 * \details H5Pmodify_filter() modifies the specified \p filter in the
 *          filter pipeline. \p plist_id must be a dataset or group
 *          creation property list.
 *
 *          The \p filter, \p flags \p cd_nelmts[], and \p cd_values
 *          parameters are used in the same manner and accept the same
 *          values as described in the discussion of H5Pset_filter().
 *
 * \version 1.8.5 Function extended to work with group creation property
 *                lists.
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pmodify_filter(hid_t plist_id, H5Z_filter_t filter, unsigned int flags, size_t cd_nelmts,
                               const unsigned int cd_values[/*cd_nelmts*/]);
/**
 * \ingroup OCPL
 *
 * \brief    Delete one or more filters in the filter pipeline
 *
 * \ocpl_id{plist_id}
 * \param[in] filter Filter to be deleted
 *
 * \return \herr_t
 *
 * \details H5Premove_filter() removes the specified \p filter from the
 *          filter pipeline in the dataset or group creation property
 *          list \p plist_id.
 *
 *          The \p filter parameter specifies the filter to be removed.
 *          Valid values for use in \p filter are as follows:
 *
 *          <table>
 *           <tr>
 *            <td>#H5Z_FILTER_ALL</td>
 *            <td>Removes all filters from the filter pipeline</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_DEFLATE</td>
 *            <td>Data compression filter, employing the gzip
 *                algorithm</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_SHUFFLE</td>
 *            <td>Data shuffling filter</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_FLETCHER32</td>
 *            <td>Error detection filter, employing the Fletcher32
 *                checksum algorithm</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_SZIP</td>
 *            <td>Data compression filter, employing the SZIP
 *                algorithm</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_NBIT</td>
 *            <td>Data compression filter, employing the N-Bit
 *                algorithm</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_SCALEOFFSET</td>
 *            <td>Data compression filter, employing the scale-offset
 *                algorithm</td>
 *           </tr>
 *          </table>
 *
 *          Additionally, user-defined filters can be removed with this
 *          routine by passing the filter identifier with which they were
 *          registered with the HDF5 library.
 *
 *          Attempting to remove a filter that is not in the filter
 *          pipeline is an error.
 *
 * \version 1.8.5 Function extended to work with group creation property
 *                lists.
 * \since 1.6.3
 *
 */
H5_DLL herr_t H5Premove_filter(hid_t plist_id, H5Z_filter_t filter);
/**
 * \ingroup OCPL
 *
 * \brief Sets tracking and indexing of attribute creation order
 *
 * \plist_id
 * \param[in] crt_order_flags Flags specifying whether to track and index
 *                            attribute creation order. \em Default: No
 *                            flag set; attribute creation order is neither
 *                            tracked not indexed
 *
 * \return \herr_t
 *
 * \details H5Pset_attr_creation_order() sets flags for tracking and
 *          indexing attribute creation order on an object.
 *
 *          \p plist_id is a dataset or group creation property list
 *          identifier.
 *
 *          \p crt_order_flags contains flags with the following meanings:
 *
 *          <table>
 *           <tr>
 *            <td>#H5P_CRT_ORDER_TRACKED</td>
 *            <td>Attribute creation order is tracked but not necessarily
 *                indexed.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5P_CRT_ORDER_INDEXED </td>
 *            <td>Attribute creation order is indexed (requires
 *                #H5P_CRT_ORDER_TRACKED).</td>
 *           </tr>
 *          </table>
 *
 *          Default behavior is that attribute creation order is neither
 *          tracked nor indexed.
 *
 *          H5Pset_attr_creation_order() can be used to set attribute
 *          creation order tracking, or to set attribute creation order
 *          tracking and indexing.
 *
 * \note If a creation order index is to be built, it must be specified in
 *       the object creation property list. HDF5 currently provides no
 *       mechanism to turn on attribute creation order tracking at object
 *       creation time and to build the index later.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_attr_creation_order(hid_t plist_id, unsigned crt_order_flags);
/**
 * \ingroup OCPL
 *
 * \brief Sets attribute storage phase change thresholds
 *
 * \plist_id
 * \param[in] max_compact  Maximum number of attributes to be stored in
 *                         compact storage (\em Default: 8); must be greater
 *                         than or equal to \p min_dense
 *
 * \param[in] min_dense    Minimum number of attributes to be stored in
 *                         dense storage (\em Default: 6)
 *
 * \return \herr_t
 *
 * \details H5Pset_attr_phase_change() sets threshold values for attribute
 *          storage on an object. These thresholds determine the point at
 *          which attribute storage changes from compact storage (i.e.,
 *          storage in the object header) to dense storage (i.e., storage
 *          in a heap and indexed with a B-tree).
 *
 *          In the general case, attributes are initially kept in compact
 *          storage. When the number of attributes exceeds \p max_compact,
 *          attribute storage switches to dense storage. If the number of
 *          attributes subsequently falls below \p min_dense, the attributes
 *          are returned to compact storage.
 *
 *          If \p max_compact is set to 0 (zero), dense storage is always
 *          used.  \p min_dense must be set to 0 (zero) when \p max_compact
 *          is 0 (zero).
 *
 *          \p plist_id is a dataset or group creation property list
 *          identifier.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_attr_phase_change(hid_t plist_id, unsigned max_compact, unsigned min_dense);
/**
 * \ingroup OCPL
 *
 * \brief Sets deflate (GNU gzip) compression method and compression level
 *
 * \ocpl_id{plist_id}
 * \param[in] level Compression level
 *
 * \return \herr_t
 *
 * \details H5Pset_deflate() sets the deflate compression method and the
 *          compression level, \p level, for a dataset or group creation
 *          property list, \p plist_id.
 *
 *          The filter identifier set in the property list is
 *          #H5Z_FILTER_DEFLATE.
 *
 *          The compression level, \p level, is a value from zero to nine,
 *          inclusive. A compression level of 0 (zero) indicates no
 *          compression; compression improves but speed slows progressively
 *          from levels 1 through 9:
 *
 *          <table>
 *            <tr>
 *              <th>Compression Level</th>
 *              <th>Gzip Action</th>
 *            </tr>
 *            <tr>
 *              <td>0</td>
 *              <td>No compression</td>
 *            </tr>
 *            <tr>
 *              <td>1</td>
 *              <td>Best compression speed; least compression</td>
 *            </tr>
 *           <tr>
 *             <td>2 through 8</td>
 *             <td>Compression improves; speed degrades</td>
 *           </tr>
 *           <tr>
 *             <td>9</td>
 *             <td>Best compression ratio; slowest speed</td>
 *           </tr>
 *          </table>
 *
 *          Note that setting the compression level to 0 (zero) does not turn
 *          off use of the gzip filter; it simply sets the filter to perform
 *          no compression as it processes the data.
 *
 *          HDF5 relies on GNU gzip for this compression.
 *
 * \version 1.8.5 Function extended to work with group creation property lists.
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_deflate(hid_t plist_id, unsigned level);
/**
 * \ingroup OCPL
 *
 * \brief Adds a filter to the filter pipeline
 *
 * \ocpl_id{plist_id}
 * \param[in] filter    Filter identifier for the filter to be added to the
 *                      pipeline
 * \param[in] flags     Bit vector specifying certain general properties of
 *                      the filter
 * \param[in] cd_nelmts Number of elements in \p c_values
 * \param[in] c_values  Auxiliary data for the filter
 *
 * \return \herr_t
 *
 * \details H5Pset_filter() adds the specified \p filter identifier and
 *          corresponding properties to the end of an output filter
 *          pipeline.
 *
 *          \p plist_id must be either a dataset creation property list or
 *          group creation property list identifier. If \p plist_id is a
 *          dataset creation property list identifier, the filter is added
 *          to the raw data filter pipeline.
 *
 *          If \p plist_id is a group creation property list identifier,
 *          the filter is added to the link filter pipeline, which filters
 *          the fractal heap used to store most of the link metadata in
 *          certain types of groups. The only predefined filters that can
 *          be set in a group creation property list are the gzip filter
 *          (#H5Z_FILTER_DEFLATE) and the Fletcher32 error detection filter
 *          (#H5Z_FILTER_FLETCHER32).
 *
 *          The array \p c_values contains \p cd_nelmts integers which are
 *          auxiliary data for the filter. The integer values will be
 *          stored in the dataset object header as part of the filter
 *          information.
 *
 *          The \p flags argument is a bit vector with the following
 *          fields specifying certain general properties of the filter:
 *
 *          <table>
 *           <tr>
 *            <td>#H5Z_FLAG_OPTIONAL</td>
 *            <td>If this bit is set then the filter is optional. If the
 *                filter fails (see below) during an H5Dwrite() operation
 *                then the filter is just excluded from the pipeline for
 *                the chunk for which it failed; the filter will not
 *                participate in the pipeline during an H5Dread() of the
 *                chunk. This is commonly used for compression filters:
 *                if the filter result would be larger than the input,
 *                then the compression filter returns failure and the
 *                uncompressed data is stored in the file.<br /><br />
 *                This flag should not be set for the Fletcher32 checksum
 *                filter as it will bypass the checksum filter without
 *                reporting checksum errors to an application.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FLAG_MANDATORY</td>
 *            <td>If the filter is required, that is, set to mandatory,
 *                and the filter fails, the library’s behavior depends
 *                on whether the chunk cache is in use:
 *                \li If the chunk cache is enabled, data chunks will
 *                    be flushed to the file during H5Dclose() and the
 *                    library will return the failure in H5Dclose().
 *                \li When the chunk cache is disabled or not big enough,
 *                    or the chunk is being evicted from the cache, the
 *                    failure will happen during H5Dwrite().
 *
 *                In each case, the library will still write to the file
 *                all data chunks that were processed by the filter
 *                before the failure occurred.<br /><br />
 *                For example, assume that an application creates a
 *                dataset of four chunks, the chunk cache is enabled and
 *                is big enough to hold all four chunks, and the filter
 *                fails when it tries to write the fourth chunk. The
 *                actual flush of the chunks will happen during
 *                H5Dclose(), not H5Dwrite(). By the time H5Dclose()
 *                fails, the first three chunks will have been written
 *                to the file. Even though H5Dclose() fails, all the
 *                resources will be released and the file can be closed
 *                properly. <br /><br />
 *                If, however, the filter fails on the second chunk, only
 *                the first chunk will be written to the file as nothing
 *                further can be written once the filter fails.</td>
 *           </tr>
 *          </table>
 *          The \p filter parameter specifies the filter to be set. Valid
 *          pre-defined filter identifiers are as follows:
 *
 *          <table>
 *           <tr>
 *            <td>#H5Z_FILTER_DEFLATE</td>
 *            <td>Data compression filter, employing the gzip
 *                algorithm</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_SHUFFLE</td>
 *            <td>Data shuffling filter</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_FLETCHER32</td>
 *            <td>Error detection filter, employing the Fletcher32
 *                checksum algorithm</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_SZIP</td>
 *            <td>Data compression filter, employing the SZIP
 *                algorithm</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_NBIT</td>
 *            <td>Data compression filter, employing the N-Bit
 *                algorithm</td>
 *           </tr>
 *           <tr>
 *            <td>#H5Z_FILTER_SCALEOFFSET</td>
 *            <td>Data compression filter, employing the scale-offset
 *                algorithm</td>
 *           </tr>
 *          </table>
 *          Also see H5Pset_edc_check() and H5Pset_filter_callback().
 *
 * \note When a non-empty filter pipeline is used with a group creation
 *       property list, the group will be created with the new group file
 *       format. The filters will come into play only when dense storage
 *       is used (see H5Pset_link_phase_change()) and will be applied to
 *       the group’s fractal heap. The fractal heap will contain most of
 *       the the group’s link metadata, including link names.
 *
 * \note When working with group creation property lists, if you are
 *       adding a filter that is not in HDF5’s set of predefined filters,
 *       i.e., a user-defined or third-party filter, you must first
 *       determine that the filter will work for a group. See the
 *       discussion of the set local and can apply callback functions
 *       in H5Zregister().
 *
 * \note If multiple filters are set for a property list, they will be
 *       applied to each chunk of raw data for datasets or each block
 *       of the fractal heap for groups in the order in which they were
 *       set.
 *
 * \note Filters can be applied only to chunked datasets; they cannot be
 *       used with other dataset storage methods, such as contiguous,
 *       compact, or external datasets.
 *
 * \note Dataset elements of variable-length and dataset region
 *       reference datatypes are stored in separate structures in the
 *       file called heaps. Filters cannot currently be applied to
 *       these heaps.
 *
 * \note <b>Filter Behavior in HDF5:</b><br />
 *       Filters can be inserted into the HDF5 pipeline to perform
 *       functions such as compression and conversion. As such, they are
 *       a very flexible aspect of HDF5; for example, a user-defined
 *       filter could provide encryption for an HDF5 dataset.
 *
 * \note A filter can be declared as either required or optional.
 *       Required is the default status; optional status must be
 *       explicitly declared.
 *
 * \note A required filter that fails or is not defined causes an
 *       entire output operation to fail; if it was applied when the
 *       data was written, such a filter will cause an input operation
 *       to fail.
 *
 * \note The following table summarizes required filter behavior.
 *          <table>
 *           <tr>
 *            <th></th>
 *            <th>Required FILTER_X not available</th>
 *            <th>FILTER_X available</th>
 *           </tr>
 *           <tr>
 *            <td>H5Pset_<FILTER_X></td>
 *            <td>Will fail.</td>
 *            <td>Will succeed.</td>
 *           </tr>
 *           <tr>
 *            <td>H5Dwrite with FILTER_X set</td>
 *            <td>Will fail.</td>
 *            <td>Will succeed; FILTER_X will be applied to
 *                the data.</td>
 *           </tr>
 *           <tr>
 *            <td>H5Dread with FILTER_X set</td>
 *            <td>Will fail.</td>
 *            <td>Will succeed.</td>
 *           </tr>
 *          </table>
 * \note An optional filter can be set for an HDF5 dataset even when
 *       the filter is not available. Such a filter can then be
 *       applied to the dataset when it becomes available on the
 *       original system or when the file containing the dataset is
 *       processed on a system on which it is available.
 *
 * \note A filter can be declared as optional through the use of the
 *       #H5Z_FLAG_OPTIONAL flag with H5Pset_filter().
 *
 * \note Consider a situation where one is creating files that will
 *       normally be used only on systems where the optional (and
 *       fictional) filter FILTER_Z is routinely available. One can
 *       create those files on system A, which lacks FILTER_Z, create
 *       chunked datasets in the files with FILTER_Z defined in the
 *       dataset creation property list, and even write data to those
 *       datasets. The dataset object header will indicate that FILTER_Z
 *       has been associated with this dataset. But since system A does
 *       not have FILTER_Z, dataset chunks will be written without it
 *       being applied.
 *
 * \note HDF5 has a mechanism for determining whether chunks are
 *       actually written with the filters specified in the object
 *       header, so while the filter remains unavailable, system A will
 *       be able to read the data. Once the file is moved to system B,
 *       where FILTER_Z is available, HDF5 will apply FILTER_Z to any
 *       data rewritten or new data written in these datasets. Dataset
 *       chunks that have been written on system B will then be
 *       unreadable on system A; chunks that have not been re-written
 *       since being written on system A will remain readable on system
 *       A. All chunks will be readable on system B.
 *
 * \note The following table summarizes optional filter behavior.
 *          <table>
 *           <tr>
 *            <th></th>
 *            <th>FILTER_Z not available</th>
 *            <th>FILTER_Z available<br /> with encode and decode</th>
 *            <th>FILTER_Z available decode only</th>
 *           </tr>
 *           <tr>
 *            <td>H5Pset_<FILTER_Z></td>
 *            <td>Will succeed.</td>
 *            <td>Will succeed.</td>
 *            <td>Will succeed.</td>
 *           </tr>
 *           <tr>
 *            <td>H5Dread with FILTER_Z set</td>
 *            <td>Will succeed if FILTER_Z has not actually<br />
 *                been applied to data.</td>
 *            <td>Will succeed.</td>
 *            <td>Will succeed.</td>
 *           </tr>
 *           <tr>
 *            <td>H5Dwrite with FILTER_Z set</td>
 *            <td>Will succeed;<br />
 *                FILTER_Z will not be applied to the data.</td>
 *            <td>Will succeed;<br />
 *            FILTER_Z will be applied to the data.</td>
 *            <td>Will succeed;<br />
 *            FILTER_Z will not be applied to the data.</td>
 *           </tr>
 *          </table>
 * \note The above principles apply generally in the use of HDF5
 *       optional filters insofar as HDF5 does as much as possible to
 *       complete an operation when an optional filter is unavailable.
 *       (The SZIP filter is an exception to this rule; see H5Pset_szip()
 *       for details.)
 *
 * \see \ref_filter_pipe, \ref_group_impls
 *
 * \version 1.8.5 Function applied to group creation property lists.
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pset_filter(hid_t plist_id, H5Z_filter_t filter, unsigned int flags, size_t cd_nelmts,
                            const unsigned int c_values[]);
/**
 * \ingroup OCPL
 *
 * \brief Sets up use of the Fletcher32 checksum filter
 *
 * \ocpl_id{plist_id}
 *
 * \return \herr_t
 *
 * \details H5Pset_fletcher32() sets the Fletcher32 checksum filter in the
 *          dataset or group creation property list \p plist_id.
 *
 * \attention The Fletcher32 EDC checksum filter was added in HDF5 Release
 *            1.6.0. In the original implementation, however, the checksum
 *            value was calculated incorrectly on little-endian systems.
 *            The error was fixed in HDF5 Release 1.6.3.
 *
 * \attention As a result of this fix, an HDF5 library of Release 1.6.0
 *            through Release 1.6.2 cannot read a dataset created or written
 *            with Release 1.6.3 or later if the dataset was created with
 *            the checksum filter and the filter is enabled in the reading
 *            library. (Libraries of Release 1.6.3 and later understand the
 *            earlier error and compensate appropriately.)
 *
 * \attention \b Work-around: An HDF5 library of Release 1.6.2 or earlier
 *            will be able to read a dataset created or written with the
 *            checksum filter by an HDF5 library of Release 1.6.3 or later
 *            if the checksum filter is disabled for the read operation.
 *            This can be accomplished via a call to H5Pset_edc_check()
 *            with the value #H5Z_DISABLE_EDC in the second parameter.
 *            This has the obvious drawback that the application will be
 *            unable to verify the checksum, but the data does remain
 *            accessible.
 *
 * \version 1.8.5 Function extended to work with group creation property
 *                lists.
 * \version 1.6.3 Error in checksum calculation on little-endian systems
 *                corrected in this release.
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pset_fletcher32(hid_t plist_id);
/**
 * \ingroup OCPL
 *
 * \brief Sets the recording of times associated with an object
 *
 * \param[in] plist_id    Object creation property list identifier
 * \param[in] track_times Boolean value, 1 or 0, specifying whether object
 *                        times are to be tracked
 *
 * \return \herr_t
 *
 * \details H5Pset_obj_track_times() sets a property in the object creation
 *          property list, \p plist_id, that governs the recording of times
 *          associated with an object.
 *
 *          If \p track_times is set to 1, time data will be recorded. If
 *          \p track_times is set to 0, time data will not be recorded.
 *
 *          Time data can be retrieved with H5Oget_info(), which will
 *          return it in the #H5O_info_t struct.
 *
 *          If times are not tracked, they will be reported as follows when queried:
 *            \Code{ 12:00 AM UDT, Jan. 1, 1970}
 *
 *          That date and time are commonly used to represent the beginning of the UNIX epoch.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_obj_track_times(hid_t plist_id, hbool_t track_times);

/* File creation property list (FCPL) routines */
/**
 * \ingroup FCPL
 *
 * \brief Retrieves the file space page size for a file creation property
 *        list
 *
 * \fcpl_id{plist_id}
 * \param[out] fsp_size  File space page size
 *
 * \return \herr_t
 *
 * \details H5Pget_file_space_page_size() retrieves the file space page
 *          size for paged aggregation in the parameter \p fsp_size.
 *
 *          The library default is 4KB (4096) if \p fsp_size is not
 *          previously set via a call to H5Pset_file_space_page_size().
 *
 * \since 1.10.1
 *
 */
H5_DLL herr_t H5Pget_file_space_page_size(hid_t plist_id, hsize_t *fsp_size);
/**
 * \ingroup FCPL
 *
 * \brief Retrieves the file space handling strategy, persisting free-space
 *        condition and threshold value for a file creation property list
 *
 * \fcpl_id{plist_id}
 * \param[out] strategy  The file space handling strategy
 * \param[out] persist   The boolean value indicating whether free space is
 *                       persistent or not
 * \param[out] threshold The free-space section size threshold value
 *
 * \return \herr_t
 *
 * \details H5Pget_file_space_strategy() retrieves the file space handling
 *          strategy, the persisting free-space condition and the threshold
 *          value in the parameters \p strategy, \p persist and
 *          \p threshold respectively.
 *
 *          The library default values returned when
 *          H5Pset_file_space_strategy() has not been called are:
 *
 *          \li \p strategy  - #H5F_FSPACE_STRATEGY_FSM_AGGR
 *          \li \p persist   - 0
 *          \li \p threshold - 1
 *
 * \since 1.10.1
 *
 */
H5_DLL herr_t H5Pget_file_space_strategy(hid_t plist_id, H5F_fspace_strategy_t *strategy, hbool_t *persist,
                                         hsize_t *threshold);
/**
 * \ingroup FCPL
 *
 * \brief Queries the 1/2 rank of an indexed storage B-tree
 *
 * \fcpl_id{plist_id}
 * \param[out] ik Pointer to location to return the chunked storage B-tree
 *                1/2 rank (<em>Default value of B-tree 1/2 rank: 32</em>)
 *
 * \return \herr_t
 *
 * \details H5Pget_istore_k() queries the 1/2 rank of an indexed storage
 *          B-tree.
 *
 *          The argument \p ik may be the null pointer (NULL).
 *          This function is valid only for file creation property lists.
 *
 * \see H5Pset_istore_k()
 *
 * \version 1.6.4 \p ik parameter type changed to \em unsigned.
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pget_istore_k(hid_t plist_id, unsigned *ik /*out*/);
/**
 * \ingroup FCPL
 *
 * \brief Retrieves the configuration settings for a shared message index
 *
 * \fcpl_id{plist_id}
 * \param[in]  index_num       Index being configured
 * \param[out] mesg_type_flags Types of messages that may be stored in
 *                             this index
 * \param[out] min_mesg_size   Minimum message size
 *
 * \return \herr_t
 *
 * \details H5Pget_shared_mesg_index() retrieves the message type and
 *          minimum message size settings from the file creation property
 *          list \p plist_id for the shared object header message index
 *          specified by \p index_num.
 *
 *          \p index_num specifies the index. \p index_num is zero-indexed,
 *          so in a file with three indexes, they will be numbered 0, 1,
 *          and 2.
 *
 *          \p mesg_type_flags and \p min_mesg_size will contain,
 *          respectively, the types of messages and the minimum size, in
 *          bytes, of messages that can be stored in this index.
 *
 *          Valid message types are described in H5Pset_shared_mesg_index().
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_shared_mesg_index(hid_t plist_id, unsigned index_num, unsigned *mesg_type_flags,
                                       unsigned *min_mesg_size);
/**
 * \ingroup FCPL
 *
 * \brief Retrieves the number of shared object header message indexes in file
 *        creation property list
 *
 * \fcpl_id{plist_id}
 * \param[out] nindexes  Number of shared object header message indexes
 *                       available in files created with this property list
 *
 * \return \herr_t
 *
 * \details H5Pget_shared_mesg_nindexes() retrieves the number of shared
 *          object header message indexes in the specified file creation
 *          property list \p plist_id.
 *
 *          If the value of \p nindexes is 0 (zero), shared object header
 *          messages are disabled in files created with this property list.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_shared_mesg_nindexes(hid_t plist_id, unsigned *nindexes);
/**
 * \ingroup FCPL
 *
 * \brief Retrieves shared object header message phase change information
 *
 * \fcpl_id{plist_id}
 * \param[out] max_list  Threshold above which storage of a shared object
 *                       header message index shifts from list to B-tree
 * \param[out] min_btree Threshold below which storage of a shared object
 *                       header message index reverts to list format
 *
 * \return \herr_t
 *
 * \details H5Pget_shared_mesg_phase_change() retrieves the threshold values
 *          for storage of shared object header message indexes in a file.
 *          These phase change thresholds determine the point at which the
 *          index storage mechanism changes from a more compact list format
 *          to a more performance-oriented B-tree format, and vice-versa.
 *
 *          By default, a shared object header message index is initially
 *          stored as a compact list. When the number of messages in an
 *          index exceeds the specified \p max_list threshold, storage
 *          switches to a B-tree format for improved performance. If the
 *          number of messages subsequently falls below the \p min_btree
 *          threshold, the index will revert to the list format.
 *
 *          If \p max_list is set to 0 (zero), shared object header message
 *          indexes in the file will always be stored as B-trees.
 *
 *          \p plist_id specifies the file creation property list.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_shared_mesg_phase_change(hid_t plist_id, unsigned *max_list, unsigned *min_btree);
/**
 * \ingroup FCPL
 *
 * \brief Retrieves the size of the offsets and lengths used in an HDF5
 *        file
 *
 * \fcpl_id{plist_id}
 * \param[out] sizeof_addr Pointer to location to return offset size in
 *             bytes
 * \param[out] sizeof_size Pointer to location to return length size in
 *             bytes
 *
 * \return \herr_t
 *
 * \details H5Pget_sizes() retrieves the size of the offsets and lengths
 *          used in an HDF5 file. This function is only valid for file
 *          creation property lists.
 *
 * \since  1.0.0
 *
 */
H5_DLL herr_t H5Pget_sizes(hid_t plist_id, size_t *sizeof_addr /*out*/, size_t *sizeof_size /*out*/);
/**
 * \ingroup FCPL
 *
 * \brief Retrieves the size of the symbol table B-tree 1/2 rank and the
 *        symbol table leaf node 1/2 size
 *
 * \fcpl_id{plist_id}
 * \param[out] ik Pointer to location to return the symbol table's B-tree
 *                1/2 rank (<em>Default value of B-tree 1/2 rank: 16</em>)
 * \param[out] lk Pointer to location to return the symbol table's leaf
 *                node 1/2 size (<em>Default value of leaf node 1/2
 *                size: 4</em>)
 *
 * \return \herr_t
 *
 * \details H5Pget_sym_k() retrieves the size of the symbol table B-tree
 *          1/2 rank and the symbol table leaf node 1/2 size.
 *
 *          This function is valid only for file creation property lists.
 *
 *          If a parameter value is set to NULL, that parameter is not
 *          retrieved.
 *
 * \see H5Pset_sym_k()
 *
 * \version 1.6.4 \p ik parameter type changed to \em unsigned
 * \version 1.6.0 The \p ik parameter has changed from type int to
 *                \em unsigned
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pget_sym_k(hid_t plist_id, unsigned *ik /*out*/, unsigned *lk /*out*/);
/**
 * \ingroup FCPL
 *
 * \brief Retrieves the size of a user block
 *
 * \fcpl_id{plist_id}
 * \param[out] size  Pointer to location to return user-block size
 *
 * \return \herr_t
 *
 * \details H5Pget_userblock() retrieves the size of a user block in a
 *          file creation property list.
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pget_userblock(hid_t plist_id, hsize_t *size);
/**
 * \ingroup FCPL
 *
 * \brief Sets the file space page size for a file creation property list
 *
 * \fcpl_id{plist_id}
 * \param[in]   fsp_size    File space page size
 *
 * \return \herr_t
 *
 * \details H5Pset_file_space_page_size() sets the file space page size
 *          \p fsp_size used in paged aggregation and paged buffering.
 *
 *          \p fsp_size has a minimum size of 512. Setting a value less
 *          than 512 will return an error. The library default size for
 *          the file space page size when not set is 4096.
 *
 *          The size set via this routine may not be changed for the life
 *          of the file.
 *
 * \since 1.10.1
 *
 */
H5_DLL herr_t H5Pset_file_space_page_size(hid_t plist_id, hsize_t fsp_size);
/**
 * \ingroup FCPL
 *
 * \brief Sets the file space handling strategy and persisting free-space
 *        values for a file creation property list
 *
 * \fcpl_id{plist_id}
 * \param[in] strategy  The file space handling strategy to be used. See:
 *                      #H5F_fspace_strategy_t
 * \param[in] persist   A boolean value to indicate whether free space
 *                      should be persistent or not
 * \param[in] threshold The smallest free-space section size that the free
 *                      space manager will track
 *
 * \return \herr_t
 *
 * \details H5Pset_file_space_strategy() sets the file space handling
 *          \p strategy, specifies persisting free-space or not (\p persist),
 *          and sets the free-space section size \p threshold in the file
 *          creation property list \p plist_id.
 *
 *          #H5F_fspace_strategy_t is a struct defined in H5Fpublic.h as
 *          follows:
 *
 *          \snippet H5Fpublic.h H5F_fspace_strategy_t_snip
 *
 *          This setting cannot be changed for the life of the file.
 *
 *          As the #H5F_FSPACE_STRATEGY_AGGR and #H5F_FSPACE_STRATEGY_NONE
 *          strategies do not use the free-space managers, the \p persist
 *          and \p threshold settings will be ignored for those strategies.
 *
 * \since 1.10.1
 *
 */
H5_DLL herr_t H5Pset_file_space_strategy(hid_t plist_id, H5F_fspace_strategy_t strategy, hbool_t persist,
                                         hsize_t threshold);
/**
 * \ingroup FCPL
 *
 * \brief Sets the size of the parameter used to control the B-trees for
 *        indexing chunked datasets
 *
 * \fcpl_id{plist_id}
 * \param[in]  ik 1/2 rank of chunked storage B-tree
 *
 * \return \herr_t
 *
 * \details H5Pset_istore_k() sets the size of the parameter used to
 *          control the B-trees for indexing chunked datasets. This
 *          function is valid only for file creation property lists.
 *
 *          \p ik is one half the rank of a tree that stores chunked
 *          raw data. On average, such a tree will be 75% full, or have
 *          an average rank of 1.5 times the value of \p ik.
 *
 *          The HDF5 library uses (\p ik*2) as the maximum # of entries
 *          before splitting a B-tree node. Since only 2 bytes are used
 *          in storing # of entries for a B-tree node in an HDF5 file,
 *          (\p ik*2) cannot exceed 65536. The default value for
 *          \p ik is 32.
 *
 * \version 1.6.4 \p ik parameter type changed to \p unsigned.
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_istore_k(hid_t plist_id, unsigned ik);
/**
 * \ingroup FCPL
 *
 * \brief Configures the specified shared object header message index
 *
 * \fcpl_id{plist_id}
 * \param[in] index_num       Index being configured
 * \param[in] mesg_type_flags Types of messages that should be stored in
 *                            this index
 * \param[in] min_mesg_size   Minimum message size
 *
 * \return \herr_t
 *
 * \details H5Pset_shared_mesg_index() is used to configure the specified
 *          shared object header message index, setting the types of
 *          messages that may be stored in the index and the minimum size
 *          of each message.
 *
 *          \p plist_id specifies the file creation property list.
 *
 *          \p index_num specifies the index to be configured.
 *          \p index_num is zero-indexed, so in a file with three indexes,
 *          they will be numbered 0, 1, and 2.
 *
 *          \p mesg_type_flags and \p min_mesg_size specify, respectively,
 *          the types and minimum size of messages that can be stored in
 *          this index.
 *
 *          Valid message types are as follows:
 *
 *          <table>
 *           <tr>
 *            <td>#H5O_SHMESG_NONE_FLAG</td>
 *            <td>No shared messages</td>
 *           </tr>
 *           <tr>
 *            <td>#H5O_SHMESG_SDSPACE_FLAG</td>
 *            <td>Simple dataspace message</td>
 *           </tr>
 *           <tr>
 *            <td>#H5O_SHMESG_DTYPE_FLAG</td>
 *            <td>Datatype message</td>
 *           </tr>
 *           <tr>
 *            <td>#H5O_SHMESG_FILL_FLAG</td>
 *            <td>Fill value message</td>
 *           </tr>
 *           <tr>
 *            <td>#H5O_SHMESG_PLINE_FLAG</td>
 *            <td>Filter pipeline message</td>
 *           </tr>
 *           <tr>
 *            <td>#H5O_SHMESG_ATTR_FLAG</td>
 *            <td>Attribute message</td>
 *           </tr>
 *           <tr>
 *            <td>#H5O_SHMESG_ALL_FLAG</td>
 *            <td>All message types; i.e., equivalent to the following:
 *            (#H5O_SHMESG_SDSPACE_FLAG | #H5O_SHMESG_DTYPE_FLAG |
 *             #H5O_SHMESG_FILL_FLAG | #H5O_SHMESG_PLINE_FLAG |
 *             #H5O_SHMESG_ATTR_FLAG)</td>
 *           </tr>
 *          </table>
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_shared_mesg_index(hid_t plist_id, unsigned index_num, unsigned mesg_type_flags,
                                       unsigned min_mesg_size);
/**
 * \ingroup FCPL
 *
 * \brief Sets number of shared object header message indexes
 *
 * \fcpl_id{plist_id}
 * \param[in] nindexes Number of shared object header message indexes to be
 *                     available in files created with this property list
 *                     (\p nindexes must be <= #H5O_SHMESG_MAX_NINDEXES (8))
 *
 * \return \herr_t
 *
 * \details H5Pset_shared_mesg_nindexes() sets the number of shared object
 *          header message indexes in the specified file creation property
 *          list.
 *
 *          This setting determines the number of shared object header
 *          message indexes, \p nindexes, that will be available in files
 *          created with this property list. These indexes can then be
 *          configured with H5Pset_shared_mesg_index().
 *
 *          If \p nindexes is set to 0 (zero), shared object header messages
 *          are disabled in files created with this property list.
 *
 *          There is a limit of #H5O_SHMESG_MAX_NINDEXES (8) that can be set
 *          with H5Pset_shared_mesg_nindexes(). An error will occur if
 *          specifying a value of \p nindexes that is greater than this value.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_shared_mesg_nindexes(hid_t plist_id, unsigned nindexes);
/**
 * \ingroup FCPL
 *
 * \brief Sets shared object header message storage phase change thresholds
 *
 * \fcpl_id{plist_id}
 * \param[in] max_list  Threshold above which storage of a shared object
 *                      header message index shifts from list to B-tree
 * \param[in] min_btree Threshold below which storage of a shared object
 *                      header message index reverts to list format
 *
 * \return \herr_t
 *
 * \details H5Pset_shared_mesg_phase_change() sets threshold values for
 *          storage of shared object header message indexes in a file.
 *          These phase change thresholds determine the point at which the
 *          index storage mechanism changes from a more compact list format
 *          to a more performance-oriented B-tree format, and vice-versa.
 *
 *          By default, a shared object header message index is initially
 *          stored as a compact list. When the number of messages in an
 *          index exceeds the threshold value of \p max_list, storage
 *          switches to a B-tree for improved performance. If the number
 *          of messages subsequently falls below the \p min_btree threshold,
 *          the index will revert to the list format.
 *
 *          If \p max_list is set to 0 (zero), shared object header message
 *          indexes in the file will be created as B-trees and will never
 *          revert to lists.
 *
 *          \p plist_id specifies the file creation property list.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_shared_mesg_phase_change(hid_t plist_id, unsigned max_list, unsigned min_btree);
/**
 * \ingroup FCPL
 *
 * \brief Sets the byte size of the offsets and lengths used to address
 *        objects in an HDF5 file
 *
 * \fcpl_id{plist_id}
 * \param[in] sizeof_addr Size of an object offset in bytes
 * \param[in] sizeof_size Size of an object length in bytes
 *
 * \return \herr_t
 *
 * \details H5Pset_sizes() sets the byte size of the offsets and lengths
 *          used to address objects in an HDF5 file. This function is only
 *          valid for file creation property lists. Passing in a value
 *          of 0 for one of the parameters retains the current value. The
 *          default value for both values is the same as sizeof(hsize_t)
 *          in the library (normally 8 bytes). Valid values currently
 *          are 2, 4, 8 and 16.
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_sizes(hid_t plist_id, size_t sizeof_addr, size_t sizeof_size);
/**
 * \ingroup FCPL
 *
 * \brief
 *
 * \fcpl_id{plist_id}
 * \param[in] ik Symbol table tree rank
 * \param[in] lk Symbol table node size
 *
 * \return \herr_t
 *
 * \details H5Pset_sym_k() sets the size of parameters used to control the
 *          symbol table nodes.
 *
 *          This function is valid only for file creation property lists.
 *          Passing in a value of zero (0) for one of the parameters retains
 *          the current value.
 *
 *          \p ik is one half the rank of a B-tree that stores a symbol
 *          table for a group. Internal nodes of the symbol table are on
 *          average 75% full. That is, the average rank of the tree is
 *          1.5 times the value of \p ik. The HDF5 library uses (\p ik*2) as
 *          the maximum # of entries before splitting a B-tree node. Since
 *          only 2 bytes are used in storing # of entries for a B-tree node
 *          in an HDF5 file, (\p ik*2) cannot exceed 65536. The default value
 *          for \p ik is 16.
 *
 *          \p lk is one half of the number of symbols that can be stored in
 *          a symbol table node. A symbol table node is the leaf of a symbol
 *          table tree which is used to store a group. When symbols are
 *          inserted randomly into a group, the group's symbol table nodes are
 *          75% full on average. That is, they contain 1.5 times the number of
 *          symbols specified by \p lk. The default value for \p lk is 4.
 *
 * \version 1.6.4 \p ik parameter type changed to \em unsigned.
 * \version 1.6.0 The \p ik parameter has changed from type int to
 *          \em unsigned.
 *
 * \since  1.0.0
 *
 */
H5_DLL herr_t H5Pset_sym_k(hid_t plist_id, unsigned ik, unsigned lk);
/**
 * \ingroup FCPL
 *
 * \brief Sets user block size
 *
 * \fcpl_id{plist_id}
 * \param[in] size Size of the user-block in bytes
 *
 * \return  \herr_t
 *
 * \details H5Pset_userblock() sets the user block size of a file creation
 *          property list. The default user block size is 0; it may be set
 *          to any power of 2 equal to 512 or greater (512, 1024, 2048, etc.).
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_userblock(hid_t plist_id, hsize_t size);

/* File access property list (FAPL) routines */
/**
 * \ingroup FAPL
 *
 * \brief Retrieves the current settings for alignment properties from a
 *        file access property list
 *
 * \fapl_id
 * \param[out] threshold Pointer to location of return threshold value
 * \param[out] alignment Pointer to location of return alignment value
 *
 * \return \herr_t
 *
 * \details H5Pget_alignment() retrieves the current settings for
 *          alignment properties from a file access property list. The
 *          \p threshold and/or \p alignment pointers may be null
 *          pointers (NULL).
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pget_alignment(hid_t fapl_id, hsize_t *threshold /*out*/, hsize_t *alignment /*out*/);
/**
 * \ingroup FAPL
 *
 * \brief Queries the raw data chunk cache parameters
 *
 * \fapl_id{plist_id}
 * \param[in,out] mdc_nelmts  <i>No longer used</i>
 * \param[in,out] rdcc_nslots Number of elements (objects) in the raw data
 *                            chunk cache
 * \param[in,out] rdcc_nbytes Total size of the raw data chunk cache, in
 *                            bytes
 * \param[in,out] rdcc_w0     Preemption policy
 *
 * \return \herr_t
 *
 * \details H5Pget_cache() retrieves the maximum possible number of
 *          elements in the raw data chunk cache, the maximum possible
 *          number of bytes in the raw data chunk cache, and the
 *          preemption policy value.
 *
 *          Any (or all) arguments may be null pointers, in which case
 *          the corresponding datum is not returned.
 *
 *          Note that the \p mdc_nelmts parameter is no longer used.
 *
 * \version 1.8.0 Use of the \p mdc_nelmts parameter discontinued.
 *                Metadata cache configuration is managed with
 *                H5Pset_mdc_config() and H5Pget_mdc_config()
 * \version 1.6.0 The \p rdcc_nbytes and \p rdcc_nslots parameters changed
 *                from type int to size_t.
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pget_cache(hid_t plist_id, int *mdc_nelmts, /* out */
                           size_t *rdcc_nslots /*out*/, size_t *rdcc_nbytes /*out*/, double *rdcc_w0);
/**
 * \ingroup FAPL
 *
 * \brief Gets information about the write tracking feature used by
 *        the core VFD
 *
 * \fapl_id
 * \param[out] is_enabled Whether the feature is enabled
 * \param[out] page_size  Size, in bytes, of write aggregation pages
 *
 * \return \herr_t
 *
 * \details H5Pget_core_write_tracking() retrieves information about the
 *          write tracking feature used by the core VFD.
 *
 *          When a file is created or opened for writing using the core
 *          virtual file driver (VFD) with the backing store option turned
 *          on, the VFD can be configured to track changes to the file
 *          and only write out the modified bytes. To avoid a large number
 *          of small writes, the changes can be aggregated into pages of
 *          a user-specified size. The core VFD is also known as the
 *          memory VFD. The driver identifier is #H5FD_CORE.
 *
 * \note This function is only for use with the core VFD and must be used
 *       after the call to H5Pset_fapl_core(). It is an error to use this
 *       function with any other VFD.
 *
 * \note This function only applies to the backing store write operation
 *       which typically occurs when the file is flushed or closed. This
 *       function has no relationship to the increment parameter passed
 *       to H5Pset_fapl_core().
 *
 * \note For optimum performance, the \p page_size parameter should be
 *       a power of two.
 *
 * \since 1.8.13
 *
 */
H5_DLL herr_t H5Pget_core_write_tracking(hid_t fapl_id, hbool_t *is_enabled, size_t *page_size);
/**
 * \ingroup FAPL
 *
 * \brief Returns low-lever driver identifier
 *
 * \plist_id
 *
 * \return \hid_t{low level driver}
 *
 * \details H5Pget_driver() returns the identifier of the low-level file
 *          driver associated with the file access property list or
 *          data transfer property list \p plist_id.
 *
 *          Valid driver identifiers distributed with HDF5 are listed and
 *          described in the following table.
 *
 *          <table>
 *           <tr>
 *            <th>Driver Name</th>
 *            <th>Driver Identifier</th>
 *            <th>Description</th>
 *            <th>Related Function</th>
 *           </tr>
 *           <tr>
 *            <td>POSIX</td>
 *            <td>#H5FD_SEC2</td>
 *            <td>This driver uses POSIX file-system functions like read and
 *                write to perform I/O to a single, permanent file on local disk
 *                with no system buffering. This driver is POSIX-compliant and
 *                is the default file driver for all systems.</td>
 *            <td>H5Pset_fapl_sec2()</td>
 *           </tr>
 *           <tr>
 *            <td>Direct</td>
 *            <td>#H5FD_DIRECT</td>
 *            <td>This is the #H5FD_SEC2 driver except data is written to or
 *                read from the file synchronously without being cached by the
 *                system.</td>
 *            <td>H5Pset_fapl_direct()</td>
 *           </tr>
 *           <tr>
 *            <td>Log</td>
 *            <td>#H5FD_LOG</td>
 *            <td>This is the #H5FD_SEC2 driver with logging capabilities.</td>
 *            <td>H5Pset_fapl_log()</td>
 *           </tr>
 *           <tr>
 *            <td>Windows</td>
 *            <td>#H5FD_WINDOWS</td>
 *            <td>This driver was modified in HDF5-1.8.8 to be a wrapper of the
 *                POSIX driver, #H5FD_SEC2. This change should not affect user
 *                applications.</td>
 *            <td>H5Pset_fapl_windows()</td>
 *           </tr>
 *           <tr>
 *            <td>STDIO</td>
 *            <td>#H5FD_STDIO</td>
 *            <td>This driver uses functions from the standard C stdio.h to
 *                perform I/O to a single, permanent file on local disk with
 *                additional system buffering.</td>
 *            <td>H5Pset_fapl_stdio()</td>
 *           </tr>
 *           <tr>
 *            <td>Memory</td>
 *            <td>#H5FD_CORE</td>
 *            <td>With this driver, an application can work with a file in
 *                memory for faster reads and writes. File contents are kept in
 *                memory until the file is closed. At closing, the memory
 *                version of the file can be written back to disk or abandoned.
 *            </td>
 *            <td>H5Pset_fapl_core()</td>
 *           </tr>
 *           <tr>
 *            <td>Family</td>
 *            <td>#H5FD_FAMILY</td>
 *            <td>With this driver, the HDF5 file’s address space is partitioned
 *                into pieces and sent to separate storage files using an
 *                underlying driver of the user’s choice. This driver is for
 *                systems that do not support files larger than 2 gigabytes.
 *            </td>
 *            <td>H5Pset_fapl_family()</td>
 *           </tr>
 *           <tr>
 *            <td>Multi</td>
 *            <td>#H5FD_MULTI</td>
 *            <td>With this driver, data can be stored in multiple files
 *                according to the type of the data. I/O might work better if
 *                data is stored in separate files based on the type of data.
 *                The Split driver is a special case of this driver.</td>
 *            <td>H5Pset_fapl_multi()</td>
 *           </tr>
 *           <tr>
 *            <td>Parallel</td>
 *            <td>#H5FD_MPIO</td>
 *            <td>This is the standard HDF5 file driver for parallel file
 *                systems. This driver uses the MPI standard for both
 *                communication and file I/O.</td>
 *            <td>H5Pset_fapl_mpio()</td>
 *           </tr>
 *           <tr>
 *            <td>Parallel POSIX</td>
 *            <td>H5FD_MPIPOSIX</td>
 *            <td>This driver is no longer available.</td>
 *            <td></td>
 *           </tr>
 *           <tr>
 *            <td>Stream</td>
 *            <td>H5FD_STREAM</td>
 *            <td>This driver is no longer available.</td>
 *            <td></td>
 *           </tr>
 *          </table>
 *
 *          This list does not include custom drivers that might be
 *          defined and registered by a user.
 *
 *          The returned driver identifier is only valid as long as the
 *          file driver remains registered.
 *
 *
 * \since 1.4.0
 *
 */
H5_DLL hid_t H5Pget_driver(hid_t plist_id);
/**
 * \ingroup FAPL
 *
 * \brief Returns a pointer to file driver information
 *
 * \param[in] plist_id File access or data transfer property list
 *                     identifier
 *
 * \return Returns a pointer to a struct containing low-level driver
 *         information. Otherwise returns NULL. NULL is also returned if
 *         no driver-specific properties have been registered. No error
 *         is pushed on the stack in this case.
 *
 * \details H5Pget_driver_info() returns a pointer to file driver-specific
 *          information for the low-level driver associated with the file
 *          access or data transfer property list \p plist_id.
 *
 *          The pointer returned by this function points to an “uncopied”
 *          struct. Driver-specific versions of that struct are defined
 *          for each low-level driver in the relevant source code file
 *          H5FD*.c. For example, the struct used for the MULTI driver is
 *          \c H5FD_multi_fapl_t defined in H5FDmulti.c.
 *
 *          If no driver-specific properties have been registered,
 *          H5Pget_driver_info() returns NULL.
 *
 * \note H5Pget_driver_info() and H5Pset_driver() are used only when
 *       creating a virtual file driver (VFD) in the virtual file
 *       layer (VFL).
 *
 * \version 1.10.1 Return value was changed from \em void * to
 *                 \em const \em void *.
 * \version 1.8.2 Function publicized in this release; previous releases
 *                described this function only in the virtual file driver
 *                documentation.
 *
 */
H5_DLL const void *H5Pget_driver_info(hid_t plist_id);
/**
 * \ingroup FAPL
 *
 * \brief Retrieves the size of the external link open file cache
 *
 * \fapl_id{plist_id}
 * \param[out] efc_size External link open file cache size in number of files
 *
 * \return \herr_t
 *
 * \details H5Pget_elink_file_cache_size() retrieves the number of files that
 *          can be held open in an external link open file cache.
 *
 * \since 1.8.7
 *
 */
H5_DLL herr_t H5Pget_elink_file_cache_size(hid_t plist_id, unsigned *efc_size);
/**
 * \ingroup FAPL
 *
 * \brief Retrieves the file access property list setting that determines
 *        whether an HDF5 object will be evicted from the library's metadata
 *        cache when it is closed
 *
 * \fapl_id
 * \param[out] evict_on_close Pointer to a variable that will indicate if
 *                            the object will be evicted on close
 *
 * \return \herr_t
 *
 * \details The library's metadata cache is fairly conservative about holding on
 *          to HDF5 object metadata (object headers, chunk index structures,
 *          etc.), which can cause the cache size to grow, resulting in memory
 *          pressure on an application or system. When enabled, the "evict on
 *          close" property will cause all metadata for an object to be
 *          immediately evicted from the cache as long as it is not referenced
 *          by any other open object.
 *
 *          See H5Pset_evict_on_close() for additional notes on behavior.
 *
 * \since 1.10.1
 *
 */
H5_DLL herr_t H5Pget_evict_on_close(hid_t fapl_id, hbool_t *evict_on_close);
/**
 * \ingroup FAPL
 *
 * \brief Retrieves a data offset from the file access property list
 *
 * \fapl_id
 * \param[out] offset Offset in bytes within the HDF5 file
 *
 * \return \herr_t
 *
 * \details H5Pget_family_offset() retrieves the value of offset from the
 *          file access property list \p fapl_id so that the user
 *          application can retrieve a file handle for low-level access to
 *          a particular member of a family of files. The file handle is
 *          retrieved with a separate call to H5Fget_vfd_handle() (or,
 *          in special circumstances, to H5FDget_vfd_handle(), see \ref VFL).
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pget_family_offset(hid_t fapl_id, hsize_t *offset);
/**
 * \ingroup FAPL
 *
 * \brief Returns the file close degree
 *
 * \fapl_id
 * \param[out] degree Pointer to a location to which to return the file
 *                    close degree property, the value of \p degree
 *
 * \return \herr_t
 *
 * \details H5Pget_fclose_degree() returns the current setting of the file
 *          close degree property \p degree in the file access property
 *          list \p fapl_id. The value of \p degree determines how
 *          aggressively H5Fclose() deals with objects within a file that
 *          remain open when H5Fclose() is called to close that file.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pget_fclose_degree(hid_t fapl_id, H5F_close_degree_t *degree);
/**
 * \ingroup FAPL
 *
 * \brief Retrieves a copy of the file image designated as the initial content
 *        and structure of a file
 *
 * \fapl_id
 * \param[in,out] buf_ptr_ptr On input, \c NULL or a pointer to a
 *                pointer to a buffer that contains the
 *                file image.\n On successful return, if \p buf_ptr_ptr is not
 *                \c NULL, \Code{*buf_ptr_ptr} will contain a pointer to a copy
 *                of the initial image provided in the last call to
 *                H5Pset_file_image() for the supplied \p fapl_id. If no initial
 *                image has been set, \Code{*buf_ptr_ptr} will be \c NULL.
 * \param[in,out] buf_len_ptr On input, \c NULL or a pointer to a buffer
 *                specifying the required size of the buffer to hold the file
 *                image.\n On successful return, if \p buf_len_ptr was not
 *                passed in as \c NULL, \p buf_len_ptr will return the required
 *                size in bytes of the buffer to hold the initial file image in
 *                the supplied file access property list, \p fapl_id. If no
 *                initial image is set, the value of \Code{*buf_len_ptr} will be
 *                set to 0 (zero)
 * \return \herr_t
 *
 * \details H5Pget_file_image() allows an application to retrieve a copy of the
 *          file image designated for a VFD to use as the initial contents of a file.
 *
 *          If file image callbacks are defined, H5Pget_file_image() will use
 *          them when allocating and loading the buffer to return to the
 *          application (see H5Pset_file_image_callbacks()). If file image
 *          callbacks are not defined, the function will use \c malloc and \c
 *          memcpy. When \c malloc and \c memcpy are used, it is the caller’s
 *          responsibility to discard the returned buffer with a call to \c
 *          free.
 *
 *          It is the responsibility of the calling application to free the
 *          buffer whose address is returned in \p buf_ptr_ptr. This can be
 *          accomplished with \c free if file image callbacks have not been set
 *          (see H5Pset_file_image_callbacks()) or with the appropriate method
 *          if file image callbacks have been set.
 *
 * \see H5LTopen_file_image(), H5Fget_file_image(), H5Pset_file_image(),
 *      H5Pset_file_image_callbacks(), H5Pget_file_image_callbacks(),
 *      \ref H5FD_file_image_callbacks_t, \ref H5FD_file_image_op_t,
 *      <a href="https://portal.hdfgroup.org/display/HDF5/HDF5+File+Image+Operations">
 *      HDF5 File Image Operations</a>.
 *
 *
 * \since 1.8.9
 *
 */
H5_DLL herr_t H5Pget_file_image(hid_t fapl_id, void **buf_ptr_ptr, size_t *buf_len_ptr);
/**
 * \ingroup FAPL
 *
 * \brief Retrieves callback routines for working with file images
 *
 * \fapl_id
 * \param[in,out] callbacks_ptr Pointer to the instance of the
 *                #H5FD_file_image_callbacks_t struct in which the callback
 *                routines are to be returned\n
 *                Struct fields must be initialized to NULL before the call
 *                is made.\n
 *                Struct field contents upon return will match those passed in
 *                in the last H5Pset_file_image_callbacks() call for the file
 *                access property list \p fapl_id.
 * \return \herr_t
 *
 * \details H5Pget_file_image_callbacks() retrieves the callback routines set for
 *          working with file images opened with the file access property list
 *          \p fapl_id.
 *
 *          The callbacks must have been previously set with
 *          H5Pset_file_image_callbacks() in the file access property list.
 *
 *          Upon the successful return of H5Pset_file_image_callbacks(), the
 *          fields in the instance of the #H5FD_file_image_callbacks_t struct
 *          pointed to by \p callbacks_ptr will contain the same values as were
 *          passed in the most recent H5Pset_file_image_callbacks() call for the
 *          file access property list \p fapl_id.
 *
 * \see H5LTopen_file_image(), H5Fget_file_image(), H5Pset_file_image(),
 *      H5Pset_file_image_callbacks(), H5Pget_file_image_callbacks(),
 *      \ref H5FD_file_image_callbacks_t, \ref H5FD_file_image_op_t,
 *      <a href="https://portal.hdfgroup.org/display/HDF5/HDF5+File+Image+Operations">
 *      HDF5 File Image Operations</a>.
 *
 * \since 1.8.9
 *
 */
H5_DLL herr_t H5Pget_file_image_callbacks(hid_t fapl_id, H5FD_file_image_callbacks_t *callbacks_ptr);
/**
 * \ingroup FAPL
 *
 * \brief Retrieves the file locking property values
 *
 * \fapl_id
 * \param[out] use_file_locking File locking flag
 * \param[out] ignore_when_disabled Ignore when disabled flag
 * \return \herr_t
 *
 * \details H5Pget_file_locking() retrieves the file locking property values for
 *          the file access property list specified by \p fapl_id.
 *
 * \since 1.10.7
 *
 */
H5_DLL herr_t H5Pget_file_locking(hid_t fapl_id, hbool_t *use_file_locking, hbool_t *ignore_when_disabled);
/**
 * \ingroup FAPL
 *
 * \brief Returns garbage collecting references setting
 *
 * \fapl_id
 * \param[out] gc_ref Flag returning the state of reference garbage
 *                    collection. A returned value of 1 indicates that
 *                    garbage collection is on while 0 indicates that
 *                    garbage collection is off.
 *
 * \return \herr_t
 *
 * \details H5Pget_gc_references() returns the current setting for the
 *          garbage collection references property from the specified
 *          file access property list. The garbage collection references
 *          property is set by H5Pset_gc_references().
 *
 * \since 1.2.0
 *
 */
H5_DLL herr_t H5Pget_gc_references(hid_t fapl_id, unsigned *gc_ref /*out*/);
/**
 * \ingroup FAPL
 *
 * \brief Retrieves library version bounds settings that indirectly control
 *        the format versions used when creating objects
 *
 * \fapl_id{plist_id}
 * \param[out] low  The earliest version of the library that will be used
 *                  for writing objects
 * \param[out] high The latest version of the library that will be used for
 *                  writing objects
 *
 * \return \herr_t
 *
 * \details H5Pget_libver_bounds() retrieves the lower and upper bounds on
 *          the HDF5 library release versions that indirectly determine the
 *          object format versions used when creating objects in the file.
 *
 *          This property is retrieved from the file access property list
 *          specified by the parameter \p fapl_id.
 *
 *          The value returned in the parameters \p low and \p high is one
 *          of the enumerated values in the #H5F_libver_t struct, which is
 *          defined in H5Fpublic.h.
 *
 * \version 1.10.2 Add #H5F_LIBVER_V18 to the enumerated defines in
 *                 #H5F_libver_t
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_libver_bounds(hid_t plist_id, H5F_libver_t *low, H5F_libver_t *high);
/**
 * \ingroup FAPL
 *
 * \brief Get the current initial metadata cache configuration from the
 *        provided file access property list
 *
 * \fapl_id{plist_id}
 * \param[in,out] config_ptr Pointer to the instance of #H5AC_cache_config_t
 *                in which the current metadata cache configuration is to be
 *                reported
 * \return \herr_t
 *
 * \note The \c in direction applies only to the \ref H5AC_cache_config_t.version
 *       field. All other fields are \c out parameters.
 *
 * \details The fields of the #H5AC_cache_config_t structure are shown
 *           below:
 *           \snippet H5ACpublic.h H5AC_cache_config_t_snip
 *           \click4more
 *
 *          H5Pget_mdc_config() gets the initial metadata cache configuration
 *          contained in a file access property list and loads it into the
 *          instance of #H5AC_cache_config_t pointed to by the \p config_ptr
 *          parameter. This configuration is used when the file is opened.
 *
 *          Note that the version field of \Code{*config_ptr} must be
 *          initialized; this allows the library to support earlier versions of
 *          the #H5AC_cache_config_t structure.
 *
 *          See the overview of the metadata cache in the special topics section
 *          of the user guide for details on the configuration data returned. If
 *          you haven't read and understood that documentation, the results of
 *          this call will not make much sense.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pget_mdc_config(hid_t plist_id, H5AC_cache_config_t *config_ptr); /* out */
/**
 * \ingroup FAPL
 *
 * \brief Retrieves the metadata cache image configuration values for a file
 *        access property list
 *
 * \fapl_id{plist_id}
 * \param[out] config_ptr Pointer to metadata cache image configuration values
 * \return \herr_t
 *
 * \details H5Pget_mdc_image_config() retrieves the metadata cache image values
 *          into \p config_ptr for the file access property list specified in \p
 *          plist_id.
 *
 *          #H5AC_cache_image_config_t is defined as follows:
 *          \snippet H5ACpublic.h H5AC_cache_image_config_t_snip
 *          \click4more
 *
 * \since 1.10.1
 */
H5_DLL herr_t H5Pget_mdc_image_config(hid_t plist_id, H5AC_cache_image_config_t *config_ptr /*out*/);
/**
 * \ingroup FAPL
 *
 * \brief Gets metadata cache logging options
 *
 * \fapl_id{plist_id}
 * \param[out] is_enabled Flag whether logging is enabled
 * \param[out] location Location of log in UTF-8/ASCII (file path/name) (On
 *             Windows, this must be ASCII)
 * \param[out] location_size Size in bytes of the location string
 * \param[out] start_on_access Whether the logging begins as soon as the file is
 *             opened or created
 * \return \herr_t
 *
 * \details The metadata cache is a central part of the HDF5 library through
 *          which all file metadata reads and writes take place. File metadata
 *          is normally invisible to the user and is used by the library for
 *          purposes such as locating and indexing data. File metadata should
 *          not be confused with user metadata, which consists of attributes
 *          created by users and attached to HDF5 objects such as datasets via
 *          \ref H5A API calls.
 *
 *          Due to the complexity of the cache, a trace/logging feature has been
 *          created that can be used by HDF5 developers for debugging and
 *          performance analysis. The functions that control this functionality
 *          will normally be of use to a very limited number of developers
 *          outside of The HDF Group. The functions have been documented to help
 *          users create logs that can be sent with bug reports.
 *
 *          Control of the log functionality is straightforward. Logging is
 *          enabled via the H5Pset_mdc_log_options() function, which will modify
 *          the file access property list used to open or create a file. This
 *          function has a flag that determines whether logging begins at file
 *          open or starts in a paused state. Log messages can then be
 *          controlled via the H5Fstart_mdc_logging() / H5Fstop_mdc_logging()
 *          functions. H5Pget_mdc_log_options() can be used to examine a file
 *          access property list, and H5Fget_mdc_logging_status() will return
 *          the current state of the logging flags.
 *
 *          The log format is described in the
 *           <a href="https://bit.ly/2PG6fNv">Metadata Cache Logging</a> document.
 *
 * \since 1.10.0
 */
H5_DLL herr_t H5Pget_mdc_log_options(hid_t plist_id, hbool_t *is_enabled, char *location,
                                     size_t *location_size, hbool_t *start_on_access);
/**
 * \ingroup FAPL
 *
 * \brief Returns the current metadata block size setting
 *
 * \fapl_id{fapl_id}
 * \param[out] size Minimum size, in bytes, of metadata block allocations
 *
 * \return \herr_t
 *
 * \details Returns the current minimum size, in bytes, of new
 *          metadata block allocations. This setting is retrieved from the
 *          file access property list \p fapl_id.
 *
 *          This value is set by H5Pset_meta_block_size() and is
 *          retrieved from the file access property list \p fapl_id.
 *
 * \since 1.4.0
 */
H5_DLL herr_t H5Pget_meta_block_size(hid_t fapl_id, hsize_t *size);
/**
 * \ingroup FAPL
 *
 * \brief Retrieves the number of read attempts from a file access
 *        property list
 *
 * \fapl_id{plist_id}
 * \param[out] attempts The number of read attempts
 *
 * \return \herr_t
 *
 * \details H5Pget_metadata_read_attempts() retrieves the number of read
 *          attempts that is set in the file access property list \p plist_id.
 *
 *          For a default file access property list, the value retrieved
 *          will depend on whether the user sets the number of attempts via
 *          H5Pset_metadata_read_attempts():
 *
 *          <ul>
 *
 *          <li>If the number of attempts is set to N, the value
 *          returned will be N.
 *          <li>If the number of attempts is not set, the value returned
 *          will be the default for non-SWMR access (1). SWMR is short
 *          for single-writer/multiple-reader.
 *          </ul>
 *
 *          For the file access property list of a specified HDF5 file,
 *          the value retrieved will depend on how the file is opened
 *          and whether the user sets the number of read attempts via
 *          H5Pset_metadata_read_attempts():
 *
 *          <ul>
 *          <li>For a file opened with SWMR access:
 *
 *          <ul>
 *              <li> If the number of attempts is set to N, the value
 *              returned will be N.
 *              <li> If the number of attempts is not set, the value
 *              returned will be the default for SWMR access (100).
 *          </ul>
 *          <li>For a file opened without SWMR access, the value
 *          retrieved will always be the default for non-SWMR access
 *          (1). The value set via H5Pset_metadata_read_attempts() does
 *          not have any effect on non-SWMR access.
 *          </ul>
 *
 * \par Failure Modes
 * \parblock
 *
 * When the input property list is not a file access property list.
 *
 * When the library is unable to retrieve the number of read attempts from
 * the file access property list.
 *
 * \endparblock
 *
 * \par Examples
 * \parblock
 *
 * The first example illustrates the two cases for retrieving the number
 * of read attempts from a default file access property list.
 *
 * \include H5Pget_metadata_read_attempts.1.c
 *
 * The second example illustrates the two cases for retrieving the
 * number of read attempts from the file access property list of a file
 * opened with SWMR acccess.
 *
 * \include H5Pget_metadata_read_attempts.2.c
 *
 * The third example illustrates the two cases for retrieving the number
 * of read attempts from the file access property list of a file opened
 * with non-SWMR acccess.
 *
 * \include H5Pget_metadata_read_attempts.3.c
 *
 * \endparblock
 *
 * \since 1.10.0
 */
H5_DLL herr_t H5Pget_metadata_read_attempts(hid_t plist_id, unsigned *attempts);
/**
 * \ingroup FAPL
 *
 * \brief Retrieves type of data property for MULTI driver
 *
 * \param[in]  fapl_id File access property list or data transfer property
 *                     list identifier
 * \param[out] type    Type of data
 *
 * \return \herr_t
 *
 * \details H5Pget_multi_type() retrieves the type of data setting from
 *          the file access or data transfer property list \p fapl_id.
 *          This enables a user application to specify the type of data
 *          the application wishes to access so that the application can
 *          retrieve a file handle for low-level access to the particular
 *          member of a set of MULTI files in which that type of data is
 *          stored. The file handle is retrieved with a separate call to
 *          H5Fget_vfd_handle() (or, in special circumstances, to
 *          H5FDget_vfd_handle(); see the Virtual File Layer documentation
 *          for more information.
 *
 *          The type of data returned in \p type will be one of those
 *          listed in the discussion of the \p type parameter in the the
 *          description of the function H5Pset_multi_type().
 *
 *          Use of this function is only appropriate for an HDF5 file
 *          written as a set of files with the MULTI file driver.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pget_multi_type(hid_t fapl_id, H5FD_mem_t *type);
/**
 * \ingroup FAPL
 *
 * \brief Retrieves the object flush property values from the file access property list
 *
 * \fapl_id{plist_id}
 * \param[in] func The user-defined callback function
 * \param[in] udata The user-defined input data for the callback function
 *
 * \return \herr_t
 *
 * \details H5Pget_object_flush_cb() gets the user-defined callback
 *          function that is set in the file access property list
 *          \p fapl_id and stored in the parameter \p func. The callback is
 *          invoked whenever an object flush occurs in the file. This
 *          routine also obtains the user-defined input data that is
 *          passed along to the callback function in the parameter
 *          \p udata.
 *
 * \par Example
 * \parblock
 * The example below illustrates the usage of this routine to obtain the
 * object flush property values.
 *
 * \include H5Pget_object_flush_cb.c
 * \endparblock
 *
 * \since 1.10.0
 */
H5_DLL herr_t H5Pget_object_flush_cb(hid_t plist_id, H5F_flush_cb_t *func, void **udata);
/**
 * \ingroup FAPL
 *
 * \brief Retrieves the maximum size for the page buffer and the minimum
          percentage for metadata and raw data pages
 *
 * \fapl_id{plist_id}
 * \param[out] buf_size Maximum size, in bytes, of the page buffer
 * \param[out] min_meta_perc Minimum metadata percentage to keep in the
 *             page buffer before allowing pages containing metadata to
 *             be evicted
 *
 * \param[out] min_raw_perc Minimum raw data percentage to keep in the
 *             page buffer before allowing pages containing raw data to
 *             be evicted
 *
 * \return \herr_t
 *
 * \details H5Pget_page_buffer_size() retrieves \p buf_size, the maximum
 *          size in bytes of the page buffer, \p min_meta_perc, the
 *          minimum metadata percentage, and \p min_raw_perc, the
 *          minimum raw data percentage.
 *
 * \since 1.10.1
 */
H5_DLL herr_t H5Pget_page_buffer_size(hid_t plist_id, size_t *buf_size, unsigned *min_meta_perc,
                                      unsigned *min_raw_perc);
/**
 * \ingroup FAPL
 *
 * \brief Returns maximum data sieve buffer size
 *
 * \fapl_id{fapl_id}
 * \param[in] size Maximum size, in bytes, of data sieve buffer
 *
 * \return \herr_t
 *
 * \details H5Pget_sieve_buf_size() retrieves, size, the current maximum
 *          size of the data sieve buffer.
 *
 *          This value is set by H5Pset_sieve_buf_size() and is retrieved
 *          from the file access property list fapl_id.
 *
 * \version 1.6.0 The \p size parameter has changed from type \c hsize_t
 *                to \c size_t
 * \since 1.4.0
 */
H5_DLL herr_t H5Pget_sieve_buf_size(hid_t fapl_id, size_t *size /*out*/);
/**
 * \ingroup FAPL
 *
 * \brief Retrieves the current small data block size setting
 *
 * \fapl_id{fapl_id}
 * \param[out] size Maximum size, in bytes, of the small data block
 *
 * \result \herr_t
 *
 * \details H5Pget_small_data_block_size() retrieves the current setting
 *          for the size of the small data block.
 *
 *          If the returned value is zero (0), the small data block
 *          mechanism has been disabled for the file.
 *
 * \since 1.4.4
 */
H5_DLL herr_t H5Pget_small_data_block_size(hid_t fapl_id, hsize_t *size /*out*/);
/**
 * \ingroup FAPL
 *
 * \brief Returns the identifier of the current VOL connector
 *
 * \fapl_id{plist_id}
 * \param[out] vol_id  Current VOL connector identifier
 *
 * \return \herr_t
 *
 * \details H5Pget_vol_id() returns the VOL connector identifier \p vol_id for
 *          the file access property list \p plist_id. This identifier should
 *          be closed with H5VLclose().
 *
 * \since 1.12.0
 *
 */
H5_DLL herr_t H5Pget_vol_id(hid_t plist_id, hid_t *vol_id);
/**
 * \ingroup FAPL
 *
 * \brief Returns a copy of the VOL information for a connector
 *
 * \fapl_id{plist_id}
 * \param[out]  vol_info  The VOL information for a connector
 *
 * \return \herr_t
 *
 * \details H5Pget_vol_info() returns a copy of the VOL information \p vol_info
 *          for a connector specified by the file access property list
 *          \p plist_id.
 *
 * \since 1.12.0
 *
 */
H5_DLL herr_t H5Pget_vol_info(hid_t plist_id, void **vol_info);
/**
 * \ingroup FAPL
 *
 * \brief Sets alignment properties of a file access property list
 *
 * \fapl_id
 * \param[in] threshold Threshold value. Note that setting the threshold
 *                      value to 0 (zero) has the effect of a special case,
 *                      forcing everything to be aligned
 * \param[in] alignment Alignment value
 *
 * \return \herr_t
 *
 * \details H5Pset_alignment() sets the alignment properties of a
 *          file access property list so that any file object greater
 *          than or equal in size to \p threshold bytes will be aligned
 *          on an address which is a multiple of \p alignment. The
 *          addresses are relative to the end of the user block; the
 *          alignment is calculated by subtracting the user block size
 *          from the absolute file address and then adjusting the address
 *          to be a multiple of \p alignment.
 *
 *          Default values for \p threshold and \p alignment are one,
 *          implying no alignment. Generally the default values will
 *          result in the best performance for single-process access to
 *          the file. For MPI IO and other parallel systems, choose an
 *          alignment which is a multiple of the disk block size.
 *
 *          If the file space handling strategy is set to
 *          #H5F_FSPACE_STRATEGY_PAGE, then the alignment set via this
 *          routine is ignored. The file space handling strategy is set
 *          by H5Pset_file_space_strategy().
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_alignment(hid_t fapl_id, hsize_t threshold, hsize_t alignment);
/**
 * \ingroup FAPL
 *
 * \brief Sets the raw data chunk cache parameters
 *
 * \fapl_id{plist_id}
 * \param[in] mdc_nelmts No longer used; any value passed is ignored
 * \param[in] rdcc_nslots The number of chunk slots in the raw data chunk
 *                        cache for this dataset. Increasing this value
 *                        reduces the number of cache collisions, but
 *                        slightly increases the memory used. Due to the
 *                        hashing strategy, this value should ideally be a
 *                        prime number. As a rule of thumb, this value
 *                        should be at least 10 times the number of chunks
 *                        that can fit in \p rdcc_nbytes bytes. For
 *                        maximum performance, this value should be set
 *                        approximately 100 times that number of chunks.
 *                        The default value is 521.
 * \param[in] rdcc_nbytes Total size of the raw data chunk cache in bytes.
 *                        The default size is 1 MB per dataset.
 * \param[in] rdcc_w0     The chunk preemption policy for all datasets.
 *                        This must be between 0 and 1 inclusive and
 *                        indicates the weighting according to which chunks
 *                        which have been fully read or written are
 *                        penalized when determining which chunks to flush
 *                        from cache. A value of 0 means fully read or
 *                        written chunks are treated no differently than
 *                        other chunks (the preemption is strictly LRU)
 *                        while a value of 1 means fully read or written
 *                        chunks are always preempted before other chunks.
 *                        If your application only reads or writes data once,
 *                        this can be safely set to 1. Otherwise, this should
 *                        be set lower depending on how often you re-read or
 *                        re-write the same data. The default value is 0.75.
 *                        If the value passed is #H5D_CHUNK_CACHE_W0_DEFAULT,
 *                        then the property will not be set on the dataset
 *                        access property list, and the parameter will come
 *                        from the file access property list.
 *
 * \return \herr_t
 *
 * \details H5Pset_cache() sets the number of elements, the total number of
 *          bytes, and the preemption policy value for all datasets in a file
 *          on the file’s file access property list.
 *
 *          The raw data chunk cache inserts chunks into the cache by first
 *          computing a hash value using the address of a chunk and then by
 *          using that hash value as the chunk’s index into the table of
 *          cached chunks. In other words, the size of this hash table and the
 *          number of possible hash values is determined by the \p rdcc_nslots
 *          parameter. If a different chunk in the cache has the same hash value,
 *          a collision will occur, which will reduce efficiency. If inserting
 *          the chunk into the cache would cause the cache to be too big, then
 *          the cache will be pruned according to the \p rdcc_w0 parameter.
 *
 *          The \p mdc_nelmts parameter is no longer used; any value passed
 *          in that parameter will be ignored.
 *
 *      \b Motivation: Setting raw data chunk cache parameters
 *       can be done with H5Pset_cache(), H5Pset_chunk_cache(),
 *       or a combination of both. H5Pset_cache() is used to
 *       adjust the chunk cache parameters for all datasets via
 *       a global setting for the file, and H5Pset_chunk_cache()
 *       is used to adjust the chunk cache parameters for
 *       individual datasets. When both are used, parameters
 *       set with H5Pset_chunk_cache() will override any parameters
 *       set with H5Pset_cache().
 *
 * \note Optimum chunk cache parameters may vary widely depending
 *       on different data layout and access patterns. For datasets
 *       with low performance requirements for example, changing
 *       the cache settings can save memory.
 *
 * \note Note: Raw dataset chunk caching is not currently
 *       supported when using the MPI I/O and MPI POSIX file drivers
 *       in read/write mode; see H5Pset_fapl_mpio() and
 *       H5Pset_fapl_mpiposix(), respectively. When using one of these
 *       file drivers, all calls to H5Dread() and H5Dwrite() will access
 *       the disk directly, and H5Pset_cache() will have no effect on
 *       performance.
 *
 * \note Raw dataset chunk caching is supported when these drivers are
 *       used in read-only mode.
 *
 * \todo Check on H5Pset_fapl_mpio() and H5Pset_fapl_mpiposix().
 *
 * \version 1.8.0 The use of the \p mdc_nelmts parameter was discontinued.
 *                Metadata cache configuration is managed with
 *                H5Pset_mdc_config() and H5Pget_mdc_config().
 * \version 1.6.0 The \p rdcc_nbytes and \p rdcc_nelmts parameters
 *                changed from type int to size_t.
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_cache(hid_t plist_id, int mdc_nelmts, size_t rdcc_nslots, size_t rdcc_nbytes,
                           double rdcc_w0);
/**
 * \ingroup FAPL
 *
 * \brief Sets write tracking information for core driver, #H5FD_CORE
 *
 * \fapl_id{fapl_id}
 * \param[in] is_enabled Boolean value specifying whether feature is
                         enabled
 * \param[in] page_size Positive integer specifying size, in bytes, of
 *                      write aggregation pages Value of 1 (one) enables
 *                      tracking with no paging.
 *
 * \return \herr_t
 *
 * \details When a file is created or opened for writing using the core
 *          virtual file driver (VFD) with the backing store option
 *          turned on, the core driver can be configured to track
 *          changes to the file and write out only the modified bytes.
 *
 *          This write tracking feature is enabled and disabled with \p
 *          is_enabled. The default setting is that write tracking is
 *          disabled, or off.
 *
 *          To avoid a large number of small writes, changes can
 *          be aggregated into pages of a user-specified size, \p
 *          page_size.
 *
 *          Setting \p page_size to 1 enables tracking with no page
 *          aggregation.
 *
 *          The backing store option is set via the function
 *          H5Pset_fapl_core.
 *
 * \attention
 * \parblock
 *            This function is only for use with the core VFD and must
 *            be used after the call to H5Pset_fapl_core(). It is an error
 *            to use this function with any other VFD.
 *
 *            It is an error to use this function when the backing store
 *            flag has not been set using H5Pset_fapl_core().
 *
 *            This function only applies to the backing store write
 *            operation which typically occurs when the file is flushed
 *            or closed. This function has no relationship to the
 *            increment parameter passed to H5Pset_fapl_core().
 *
 *            For optimum performance, the \p page_size parameter should be
 *            a power of two.
 *
 *            It is an error to set the page size to 0.
 * \endparblock
 *
 * \version 1.8.14 C function modified in this release to return error
 *                 if \p page_size is set to 0 (zero).
 * \since 1.8.13
 *
 */
H5_DLL herr_t H5Pset_core_write_tracking(hid_t fapl_id, hbool_t is_enabled, size_t page_size);
/**
 * \ingroup FAPL
 *
 * \brief Sets a file driver
 *
 * \plist_id
 * \param[in] driver_id   The new driver identifier
 * \param[in] driver_info Optional struct containing driver properties
 *
 * \return \herr_t
 *
 * \details H5Pset_driver() sets the file driver, driver_id, for a file
 *          access or data transfer property list, \p plist_id, and
 *          supplies an optional struct containing the driver-specific
 *          properties, \p driver_info.
 *
 *          The driver properties will be copied into the property list
 *          and the reference count on the driver will be incremented,
 *          allowing the caller to close the driver identifier but still
 *          use the property list.
 *
 * \version 1.8.2 Function publicized in this release; previous releases
 *                described this function only in the virtual file driver
 *                documentation.
 *
 */
H5_DLL herr_t H5Pset_driver(hid_t plist_id, hid_t driver_id, const void *driver_info);
/**
 * \ingroup FAPL
 *
 * \brief Sets the number of files that can be held open in an external
 *        link open file cache
 *
 * \par Motivation
 * \parblock
 * The <em>external link open file cache</em> holds files open after
 * they have been accessed via an external link. This cache reduces
 * the number of times such files are opened when external links are
 * accessed repeatedly and can siginificantly improves performance in
 * certain heavy-use situations and when low-level file opens or closes
 * are expensive.
 *
 * H5Pset_elink_file_cache_size() sets the number of files
 * that will be held open in an external link open file
 * cache. H5Pget_elink_file_cache_size() retrieves the size of an existing
 * cache; and H5Fclear_elink_file_cache() clears an existing cache without
 * closing it.
 * \endparblock
 *
 * \fapl_id{plist_id}
 * \param[in] efc_size External link open file cache size in number of files
 *                     <em>Default setting is 0 (zero).</em>
 *
 * \return \herr_t
 *
 * \details H5Pset_elink_file_cache_size() specifies the number of files
 *          that will be held open in an external link open file cache.
 *
 *          The default external link open file cache size is 0 (zero),
 *          meaning that files accessed via an external link are not
 *          held open. Setting the cache size to a positive integer
 *          turns on the cache; setting the size back to zero turns it
 *          off.
 *
 *          With this property set, files are placed in the external
 *          link open file cache cache when they are opened via an
 *          external link. Files are then held open until either
 *          they are evicted from the cache or the parent file is
 *          closed. This property setting can improve performance when
 *          external links are repeatedly accessed.
 *
 *          When the cache is full, files will be evicted using a least
 *          recently used (LRU) scheme; the file which has gone the
 *          longest time without being accessed through the parent file
 *          will be evicted and closed if nothing else is holding that
 *          file open.
 *
 *          Files opened through external links inherit the parent
 *          file’s file access property list by default, and therefore
 *          inherit the parent file’s external link open file cache
 *          setting.
 *
 *          When child files contain external links of their own, the
 *          caches can form a graph of cached external files. Closing
 *          the last external reference to such a graph will recursively
 *          close all files in the graph, even if cycles are present.
 * \par Example
 * \parblock
 * The following code sets up an external link open file cache that will
 * hold open up to 8 files reached through external links:
 *
 * \code
 * status = H5Pset_elink_file_cache_size(fapl_id, 8);
 * \endcode
 * \endparblock
 *
 * \since 1.8.7
 */
H5_DLL herr_t H5Pset_elink_file_cache_size(hid_t plist_id, unsigned efc_size);
/**
 * \ingroup FAPL
 *
 * \brief Controls the library's behavior of evicting metadata associated with
 *        a closed object
 *
 * \fapl_id
 * \param[in] evict_on_close Whether the HDF5 object should be evicted on close
 *
 * \return \herr_t
 *
 * \details The library's metadata cache is fairly conservative about holding
 *          on to HDF5 object metadata(object headers, chunk index structures,
 *          etc.), which can cause the cache size to grow, resulting in memory
 *          pressure on an application or system. When enabled, the "evict on
 *          close" property will cause all metadata for an object to be evicted
 *          from the cache as long as metadata is not referenced by any other
 *          open object.
 *
 *          This function only applies to file access property lists.
 *
 *          The default library behavior is to not evict on object or file
 *          close.
 *
 *          When applied to a file access property list, any subsequently opened
 *          object will inherit the "evict on close" property and will have
 *          its metadata evicted when the object is closed.
 *
 * \since 1.10.1
 *
 */
H5_DLL herr_t H5Pset_evict_on_close(hid_t fapl_id, hbool_t evict_on_close);
/**
 * \ingroup FAPL
 *
 * \brief Sets offset property for low-level access to a file in a family of
 *        files
 *
 * \fapl_id
 * \param[in] offset Offset in bytes within the HDF5 file
 *
 * \return \herr_t
 *
 * \details H5Pset_family_offset() sets the offset property in the file access
 *          property list \p fapl_id so that the user application can
 *          retrieve a file handle for low-level access to a particular member
 *          of a family of files. The file handle is retrieved with a separate
 *          call to H5Fget_vfd_handle() (or, in special circumstances, to
 *          H5FDget_vfd_handle(); see \ref VFL).
 *
 *          The value of \p offset is an offset in bytes from the beginning of
 *          the HDF5 file, identifying a user-determined location within the
 *          HDF5 file.
 *          The file handle the user application is seeking is for the specific
 *          member-file in the associated family of files to which this offset
 *          is mapped.
 *
 *          Use of this function is only appropriate for an HDF5 file written as
 *          a family of files with the \c FAMILY file driver.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pset_family_offset(hid_t fapl_id, hsize_t offset);
/**
 * \ingroup FAPL
 *
 * \brief Sets the file close degree
 *
 * \fapl_id
 * \param[in] degree Pointer to a location containing the file close
 *           degree property, the value of \p degree
 *
 * \return \herr_t
 *
 * \details H5Pset_fclose_degree() sets the file close degree property
 *          \p degree in the file access property list \p fapl_id.
 *
 *          The value of \p degree determines how aggressively
 *          H5Fclose() deals with objects within a file that remain open
 *          when H5Fclose() is called to close that file. \p degree can
 *          have any one of four valid values:
 *
 *          <table>
 *           <tr>
 *            <th>Degree name</th>
 *            <th>H5Fclose behavior with no open object in file</th>
 *            <th>H5Fclose behavior with open object(s) in file</th>
 *           </tr>
 *           <tr>
 *            <td>#H5F_CLOSE_WEAK</td>
 *            <td>Actual file is closed.</td>
 *            <td>Access to file identifier is terminated; actual file
 *                close is delayed until all objects in file are closed
 *            </td>
 *           </tr>
 *           <tr>
 *            <td>#H5F_CLOSE_SEMI</td>
 *            <td>Actual file is closed.</td>
 *            <td>Function returns FAILURE</td>
 *           </tr>
 *           <tr>
 *            <td>#H5F_CLOSE_STRONG</td>
 *            <td>Actual file is closed.</td>
 *            <td>All open objects remaining in the file are closed then
 *                file is closed</td>
 *           </tr>
 *           <tr>
 *            <td>#H5F_CLOSE_DEFAULT</td>
 *            <td>The VFL driver chooses the behavior. Currently, all VFL
 *            drivers set this value to #H5F_CLOSE_WEAK, except for the
 *            MPI-I/O driver, which sets it to #H5F_CLOSE_SEMI.</td>
 *            <td></td>
 *           </tr>
 *
 *          </table>
 * \warning If a file is opened multiple times without being closed, each
 *          open operation must use the same file close degree setting.
 *          For example, if a file is already open with #H5F_CLOSE_WEAK,
 *          an H5Fopen() call with #H5F_CLOSE_STRONG will fail.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pset_fclose_degree(hid_t fapl_id, H5F_close_degree_t degree);
/**
 * \ingroup FAPL
 *
 * \brief Sets an initial file image in a memory buffer
 *
 * \fapl_id
 * \param[in] buf_ptr Pointer to the initial file image, or
 *                    NULL if no initial file image is desired
 * \param[in] buf_len Size of the supplied buffer, or
 *                    0 (zero) if no initial image is desired
 *
 * \return \herr_t
 *
 * \details H5Pset_file_image() allows an application to provide a file image
 *          to be used as the initial contents of a file.
 *          Calling H5Pset_file_image()makes a copy of the buffer specified in
 *          \p buf_ptr of size \p buf_len.
 *
 *          \par Motivation:
 *          H5Pset_file_image() and other elements of HDF5 are
 *          used to load an image of an HDF5 file into system memory and open
 *          that image as a regular HDF5 file. An application can then use the
 *          file without the overhead of disk I/O.
 *
 *          \par Recommended Reading:
 *          This function is part of the file image
 *          operations feature set. It is highly recommended to study the guide
 *          [<em>HDF5 File Image Operations</em>]
 *          (https://portal.hdfgroup.org/display/HDF5/HDF5+File+Image+Operations
 *          ) before using this feature set. See the “See Also” section below
 *          for links to other elements of HDF5 file image operations.
 *
 * \see
 *    \li H5LTopen_file_image()
 *    \li H5Fget_file_image()
 *    \li H5Pget_file_image()
 *    \li H5Pset_file_image_callbacks()
 *    \li H5Pget_file_image_callbacks()
 *
 *    \li [HDF5 File Image Operations]
 *        (https://portal.hdfgroup.org/display/HDF5/HDF5+File+Image+Operations)
 *        in [Advanced Topics in HDF5]
 *        (https://portal.hdfgroup.org/display/HDF5/Advanced+Topics+in+HDF5)
 *
 *    \li Within H5Pset_file_image_callbacks():
 *    \li Callback #H5FD_file_image_callbacks_t
 *    \li Callback #H5FD_file_image_op_t
 *
 * \version 1.8.13 Fortran subroutine added in this release.
 * \since 1.8.9
 *
 */
H5_DLL herr_t H5Pset_file_image(hid_t fapl_id, void *buf_ptr, size_t buf_len);
/**
 * \ingroup FAPL
 *
 * \brief Sets the callbacks for working with file images
 *
 * \note      **Motivation:** H5Pset_file_image_callbacks() and other elements
 *            of HDF5 are used to load an image of an HDF5 file into system
 *            memory and open that image as a regular HDF5 file. An application
 *            can then use the file without the overhead of disk I/O.\n
 *            **Recommended Reading:** This function is part of the file
 *            image operations feature set. It is highly recommended to study
 *            the guide [HDF5 File Image Operations]
 *            (https://portal.hdfgroup.org/display/HDF5/HDF5+File+Image+Operations
 *            ) before using this feature set. See the “See Also” section below
 *            for links to other elements of HDF5 file image operations.
 *
 * \fapl_id
 * \param[in,out] callbacks_ptr Pointer to the instance of the
 *                #H5FD_file_image_callbacks_t structure
 *
 * \return \herr_t \n
 *         **Failure Modes**: Due to interactions between this function and
 *         H5Pset_file_image() and H5Pget_file_image(),
 *         H5Pset_file_image_callbacks() will fail if a file image has
 *         already been set in the target file access property list, \p fapl_id.
 *
 * \details H5Pset_file_image_callbacks() sets callback functions for working
 *          with file images in memory.
 *
 *          H5Pset_file_image_callbacks() allows an application to control the
 *          management of file image buffers through user defined callbacks.
 *          These callbacks can be used in the management of file image buffers
 *          in property lists and with certain file drivers.
 *
 *          H5Pset_file_image_callbacks() must be used before any file image has
 *          been set in the file access property list. Once a file image has
 *          been set, the function will fail.
 *
 *          The callback routines set up by H5Pset_file_image_callbacks() are
 *          invoked when a new file image buffer is allocated, when an existing
 *          file image buffer is copied or resized, or when a file image buffer
 *          is released from use.
 *
 *          Some file drivers allow the use of user-defined callback functions
 *          for allocating, freeing, and copying the driver’s internal buffer,
 *          potentially allowing optimizations such as avoiding large \c malloc
 *          and \c memcpy operations, or to perform detailed logging.
 *
 *          From the perspective of the HDF5 library, the operations of the
 *          \ref H5FD_file_image_callbacks_t.image_malloc "image_malloc",
 *          \ref H5FD_file_image_callbacks_t.image_memcpy "image_memcpy",
 *          \ref H5FD_file_image_callbacks_t.image_realloc "image_realloc", and
 *          \ref H5FD_file_image_callbacks_t.image_free "image_free" callbacks
 *          must be identical to those of the
 *          corresponding C standard library calls (\c malloc, \c memcpy,
 *          \c realloc, and \c free). While the operations must be identical,
 *          the file image callbacks have more parameters. The return values
 *          of \ref H5FD_file_image_callbacks_t.image_malloc "image_malloc" and
 *          \ref H5FD_file_image_callbacks_t.image_realloc "image_realloc" are identical to
 *          the return values of \c malloc and \c realloc. The return values of
 *          \ref H5FD_file_image_callbacks_t.image_malloc "image_malloc" and
 *          \ref H5FD_file_image_callbacks_t.image_free "image_free" differ from the return
 *          values of \c memcpy and \c free in that the return values of
 *          \ref H5FD_file_image_callbacks_t.image_memcpy "image_memcpy" and
 *          \ref H5FD_file_image_callbacks_t.image_free "image_free" can also indicate failure.
 *
 *          The callbacks and their parameters, along with a struct and
 *          an \c ENUM required for their use, are described below.
 *
 *          <b>Callback struct and \c ENUM:</b>
 *
 *          The callback functions set up by H5Pset_file_image_callbacks() use
 *          a struct and an \c ENUM that are defined as follows
 *
 *          The struct #H5FD_file_image_callbacks_t serves as a container
 *          for the callback functions and a pointer to user-supplied data.
 *          The struct is defined as follows:
 *          \snippet H5FDpublic.h H5FD_file_image_callbacks_t_snip
 *
 *          Elements of the #H5FD_file_image_op_t are used by the
 *          callbacks to invoke certain operations on file images. The ENUM is
 *          defined as follows:
 *          \snippet H5FDpublic.h H5FD_file_image_op_t_snip
 *
 *          The elements of the #H5FD_file_image_op_t are used in the following
 *          callbacks:
 *
 *          - The \ref H5FD_file_image_callbacks_t.image_malloc "image_malloc" callback
 *          contains a pointer to a function that must appear to HDF5 to have
 *          functionality identical to that of the standard C library \c malloc() call.
 *
 *          - Signature in #H5FD_file_image_callbacks_t:
 *          \snippet H5FDpublic.h image_malloc_snip
 *          \n
 *          - The \ref H5FD_file_image_callbacks_t.image_memcpy "image_memcpy"
 *          callback contains a pointer to a function
 *          that must appear to HDF5 to have functionality identical to that
 *          of the standard C library \c memcopy() call, except that it returns
 *          a \p NULL on failure. (The \c memcpy C Library routine is defined
 *          to return the \p dest parameter in all cases.)
 *
 *          - Setting \ref H5FD_file_image_callbacks_t.image_memcpy "image_memcpy"
 *          to \c NULL indicates that HDF5 should invoke
 *          the standard C library \c memcpy() routine when copying buffers.
 *
 *          - Signature in #H5FD_file_image_callbacks_t:
 *          \snippet H5FDpublic.h image_memcpy_snip
 *          \n
 *          - The \ref H5FD_file_image_callbacks_t.image_realloc "image_realloc" callback
 *          contains a pointer to a function that must appear to HDF5 to have
 *          functionality identical to that of the standard C library \c realloc() call.
 *
 *          - Setting \ref H5FD_file_image_callbacks_t.image_realloc "image_realloc"
 *          to \p NULL indicates that HDF5 should
 *          invoke the standard C library \c realloc() routine when resizing
 *          file image buffers.
 *
 *          - Signature in #H5FD_file_image_callbacks_t:
 *          \snippet H5FDpublic.h image_realloc_snip
 *          \n
 *          - The \ref H5FD_file_image_callbacks_t.image_free "image_free" callback contains
 *          a pointer to a function that must appear to HDF5 to have functionality
 *          identical to that of the standard C library \c free() call, except
 *          that it will return \c 0 (\c SUCCEED) on success and \c -1 (\c FAIL) on failure.
 *
 *          - Setting \ref H5FD_file_image_callbacks_t.image_free "image_free"
 *          to \c NULL indicates that HDF5 should invoke
 *          the standard C library \c free() routine when releasing file image
 *          buffers.
 *
 *          - Signature in #H5FD_file_image_callbacks_t:
 *          \snippet H5FDpublic.h image_free_snip
 *          \n
 *          - The  \ref H5FD_file_image_callbacks_t.udata_copy "udata_copy"
 *          callback contains a pointer to a function
 *          that, from the perspective of HDF5, allocates a buffer of suitable
 *          size, copies the contents of the supplied \p udata into the new
 *          buffer, and returns the address of the new buffer. The function
 *          returns NULL on failure. This function is necessary if a non-NULL
 *          \p udata parameter is supplied, so that property lists containing
 *          the image callbacks can be copied. If the \p udata parameter below
 *          is \c NULL, then this parameter should be \c NULL as well.
 *
 *          - Signature in #H5FD_file_image_callbacks_t:
 *          \snippet H5FDpublic.h udata_copy_snip
 *          \n
 *          - The \ref H5FD_file_image_callbacks_t.udata_free "udata_free"
 *          callback contains a pointer to a function
 *          that, from the perspective of HDF5, frees a user data block. This
 *          function is necessary if a non-NULL udata parameter is supplied so
 *          that property lists containing image callbacks can be discarded
 *          without a memory leak. If the udata parameter below is \c NULL,
 *          this parameter should be \c NULL as well.
 *
 *          - Signature in #H5FD_file_image_callbacks_t:
 *          \snippet H5FDpublic.h udata_free_snip
 *
 *          - \p **udata**, the final field in the #H5FD_file_image_callbacks_t
 *          struct, provides a pointer to user-defined data. This pointer will
 *          be passed to the
 *          \ref H5FD_file_image_callbacks_t.image_malloc "image_malloc",
 *          \ref H5FD_file_image_callbacks_t.image_memcpy "image_memcpy",
 *          \ref H5FD_file_image_callbacks_t.image_realloc "image_realloc", and
 *          \ref H5FD_file_image_callbacks_t.image_free "image_free" callbacks.
 *          Define udata as \c NULL if no user-defined data is provided.
 *
 * \since 1.8.9
 *
 */
H5_DLL herr_t H5Pset_file_image_callbacks(hid_t fapl_id, H5FD_file_image_callbacks_t *callbacks_ptr);
/**
 * \ingroup FAPL
 *
 * \brief Sets the file locking property values
 *
 * \fapl_id
 * \param[in] use_file_locking Toggle to specify file locking (or not)
 * \param[in] ignore_when_disabled Toggle to ignore when disabled (or not)
 *
 * \return \herr_t
 *
 * \details H5Pset_file_locking() overrides the default file locking flag
 *          setting that was set when the library was configured.
 *
 *          This setting can be overridden by the \c HDF5_USE_FILE_LOCKING
 *          environment variable.
 *
 *          File locking is used when creating/opening a file to prevent
 *          problematic file accesses.
 *
 * \since 1.10.7
 *
 */
H5_DLL herr_t H5Pset_file_locking(hid_t fapl_id, hbool_t use_file_locking, hbool_t ignore_when_disabled);
/**
 * \ingroup FAPL
 *
 * \brief Sets garbage collecting references flag
 *
 * \fapl_id
 * \param[in] gc_ref Flag setting reference garbage collection to on (1) or off (0)
 *
 * \return \herr_t
 *
 * \details H5Pset_gc_references() sets the flag for garbage collecting
 *          references for the file.
 *
 *          Dataset region references and other reference types use space in an
 *          HDF5 file's global heap. If garbage collection is on and the user
 *          passes in an uninitialized value in a reference structure, the heap
 *          might get corrupted. When garbage collection is off, however, and
 *          the user re-uses a reference, the previous heap block will be
 *          orphaned and not returned to the free heap space.
 *
 *          When garbage collection is on, the user must initialize the
 *          reference structures to 0 or risk heap corruption.
 *
 *          The default value for garbage collecting references is off.
 *
 */
H5_DLL herr_t H5Pset_gc_references(hid_t fapl_id, unsigned gc_ref);
/**
 * \ingroup FAPL
 *
 * \brief Controls the range of library release versions used when creating
 *        objects in a file
 *
 * \fapl_id{plist_id}
 * \param[in] low  The earliest version of the library that will be used
 *                 for writing objects
 * \param[in] high The latest version of the library that will be used for
 *                 writing objects
 *
 * \return \herr_t
 *
 * \details H5Pset_libver_bounds() controls the range of library release
 *          versions that will be used when creating objects in a file.
 *          The object format versions are determined indirectly from the
 *          library release versions specified in the call.
 *
 *          This property is set in the file access property list
 *          specified by the parameter \p fapl_id.
 *
 *          The parameter \p low sets the earliest possible format
 *          versions that the library will use when creating objects in
 *          the file.  Note that earliest possible is different from
 *          earliest, as some features introduced in library versions
 *          later than 1.0.0 resulted in updates to object formats.
 *          The parameter \p high sets the latest format versions that
 *          the library will be allowed to use when creating objects in
 *          the file.
 *
 *          The parameters \p low and \p high must be one of the
 *          enumerated values in the #H5F_libver_t struct, which is
 *          defined in H5Fpublic.h.
 *
 *          The macro #H5F_LIBVER_LATEST is aliased to the highest
 *          enumerated value in #H5F_libver_t, indicating that this is
 *          currently the latest format available.
 *
 *          The library supports the following five pairs of
 *          (\p low, \p high) combinations as derived from the values
 *          in #H5F_libver_t:
 *
 *          <table>
 *           <tr>
 *            <th>Value of \p low and \p high</th>
 *            <th>Result</th>
 *           </tr>
 *           <tr>
 *            <td>\p low=#H5F_LIBVER_EARLIEST<br />
 *                \p high=#H5F_LIBVER_V18</td>
 *            <td>
 *              \li The library will create objects with the earliest
 *                  possible format versions.
 *              \li The library will allow objects to be created with the
 *                  latest format versions available to library release 1.8.x.
 *              \li API calls that create objects or features that are
 *                  available to versions of the library greater than 1.8.x
 *                  release will fail.
 *             </td>
 *           </tr>
 *           <tr>
 *            <td>\p low=#H5F_LIBVER_EARLIEST<br />
 *                \p high=#H5F_LIBVER_V110</td>
 *            <td>
 *             \li The library will create objects with the earliest possible
 *                 format versions.
 *             \li The library will allow objects to be created with the latest
 *                 format versions available to library release 1.10.x.
 *                 Since 1.10.x is also #H5F_LIBVER_LATEST, there is no upper
 *                 limit on the format versions to use.  For example, if a newer
 *                 format version is required to support a feature e.g. virtual
 *                 dataset, this setting will allow the object to be created.
 *             \li This is the library default setting and provides the greatest
 *                 format compatibility.
 *            </td>
 *           </tr>
 *           <tr>
 *            <td>\p low=#H5F_LIBVER_V18<br />
 *                \p high=#H5F_LIBVER_V18</td>
 *            <td>
 *             \li The library will create objects with the latest format
 *                 versions available to library release 1.8.x.
 *             \li API calls that create objects or features that are available
 *                 to versions of the library greater than 1.8.x release will
 *                 fail.
 *             \li Earlier versions of the library may not be able to access
 *                 objects created with this setting.</td>
 *           </tr>
 *           <tr>
 *            <td>\p low=#H5F_LIBVER_V18<br />
 *                \p high=#H5F_LIBVER_V110</td>
 *            <td>
 *              \li The library will create objects with the latest format
 *                  versions available to library release 1.8.x.
 *              \li The library will allow objects to be created with the latest
 *                  format versions available to library release 1.10.x.
 *                  Since 1.10.x is also #H5F_LIBVER_LATEST, there is no upper
 *                  limit on the format versions to use.  For example, if a
 *                  newer format version is required to support a feature e.g.
 *                  virtual dataset, this setting will allow the object to be
 *                  created.
 *              \li Earlier versions of the library may not be able to access
 *                  objects created with this setting.</td>
 *           </tr>
 *           <tr>
 *            <td>\p low=#H5F_LIBVER_V110<br />
 *                \p high=#H5F_LIBVER_V110
 *             </td>
 *             <td>
 *              \li The library will create objects with the latest format
 *                  versions available to library release 1.10.x.
 *              \li The library will allow objects to be created with the latest
 *                  format versions available to library release 1.10.x.
 *                  Since 1.10.x is also #H5F_LIBVER_LATEST, there is no upper
 *                  limit on the format versions to use. For example, if a
 *                  newer format version is required to support a feature e.g.
 *                  virtual dataset, this setting will allow the object to be
 *                  created.
 *              \li This setting allows users to take advantage of the latest
 *                  features and performance enhancements in the library.
 *                  However, objects written with this setting may be
 *                  accessible to a smaller range of library versions than
 *                  would be the case if low is set to #H5F_LIBVER_EARLIEST.
 *              \li Earlier versions of the library may not be able to access
 *                  objects created with this
 * setting.
 *            </td>
 *           </tr>
 *          </table>
 *
 * \version 1.10.2 #H5F_LIBVER_V18 added to the enumerated defines in
 *                 #H5F_libver_t.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_libver_bounds(hid_t plist_id, H5F_libver_t low, H5F_libver_t high);
/**
 * \ingroup FAPL
 *
 * \brief Set the initial metadata cache configuration in the indicated File
 *        Access Property List to the supplied value
 *
 * \fapl_id{plist_id}
 * \param[in] config_ptr  Pointer to the instance of \p H5AC_cache_config_t
 *            containing the desired configuration
 * \return \herr_t
 *
 *  \details The fields of the #H5AC_cache_config_t structure are shown
 *           below:
 *           \snippet H5ACpublic.h H5AC_cache_config_t_snip
 *           \click4more
 *
 * \details H5Pset_mdc_config() attempts to set the initial metadata cache
 *          configuration to the supplied value.  It will fail if an invalid
 *          configuration is detected.  This configuration is used when the file
 *          is opened.
 *
 *          See the overview of the metadata cache in the special topics section
 *          of the user manual for details on what is being configured. If you
 *          have not read and understood that documentation, you really should
 *          not be using this API call.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_mdc_config(hid_t plist_id, H5AC_cache_config_t *config_ptr);
/**
 * \ingroup FAPL
 *
 * \brief Sets metadata cache logging options
 *
 * \fapl_id{plist_id}
 * \param[in] is_enabled  Whether logging is enabled
 * \param[in] location Location of log in UTF-8/ASCII (file path/name)
 *            (On Windows, this must be ASCII)
 * \param[in] start_on_access  Whether the logging will begin as soon as the
 *            file is opened or created
 *
 * \return \herr_t
 *
 * \details The metadata cache is a central part of the HDF5 library through
 *          which all file metadata reads and writes take place. File metadata
 *          is normally invisible to the user and is used by the library for
 *          purposes such as locating and indexing data. File metadata should
 *          not be confused with user metadata, which consists of attributes
 *          created by users and attached to HDF5 objects such as datasets via
 *          H5A API calls.
 *
 *          Due to the complexity of the cache, a trace/logging feature has
 *          been created that can be used by HDF5 developers for debugging and
 *          performance analysis. The functions that control this functionality
 *          will normally be of use to a very limited number of developers
 *          outside of The HDF Group. The functions have been documented to
 *          help users create logs that can be sent with bug reports.
 *
 *          Control of the log functionality is straightforward. Logging is
 *          enabled via the H5Pset_mdc_log_options() function,
 *          which will modify the file access property list used to open or
 *          create a file. This function has a flag that determines whether
 *          logging begins at file open or starts in a paused state. Log
 *          messages can then be controlled via the H5Fstart_mdc_logging()
 *          and H5Fstop_mdc_logging() function.
 *
 *          H5Pget_mdc_log_options() can be used to examine a file access
 *          property list, and H5Fget_mdc_logging_status() will return the
 *          current state of the logging flags.
 *
 *          The log format is described in [<em>Metadata Cache Logging</em>]
 *          (https://portal.hdfgroup.org/display/HDF5/Fine-tuning+the+Metadata+Cache).
 *
 * \since 1.10.0
 *
 */
H5_DLL herr_t H5Pset_mdc_log_options(hid_t plist_id, hbool_t is_enabled, const char *location,
                                     hbool_t start_on_access);
/**
 * \ingroup FAPL
 *
 * \brief Sets the minimum metadata block size
 *
 * \fapl_id{fapl_id}
 * \param[in] size Minimum size, in bytes, of metadata block allocations
 *
 * \return \herr_t
 *
 * \details H5Pset_meta_block_size() sets the minimum size, in bytes, of
 *          metadata block allocations when #H5FD_FEAT_AGGREGATE_METADATA is set by a VFL
 *          driver.

 *          Each raw metadata block is initially allocated to be of the given size.
 *          Specific metadata objects (e.g., object headers, local heaps, B-trees) are then
 *          sub-allocated from this block.
 *
 *          The default setting is 2048 bytes, meaning that the library will
 *          attempt to aggregate metadata in at least 2K blocks in the file.
 *          Setting the value to zero (\Code{0}) with this function will turn
 *          off metadata aggregation, even if the VFL driver attempts to use the
 *          metadata aggregation strategy.
 *
 *          Metadata aggregation reduces the number of small data objects in the file that
 *          would otherwise be required for metadata. The aggregated block of metadata is
 *          usually written in a single write action and always in a contiguous block,
 *          potentially significantly improving library and application performance.
 *
 * \since 1.4.0
 */
H5_DLL herr_t H5Pset_meta_block_size(hid_t fapl_id, hsize_t size);
/**
 * \ingroup FAPL
 *
 * \brief Sets the number of read attempts in a file access property list
 *
 * \fapl_id{plist_id}
 * \param[in] attempts The number of read attempts. Must be a value greater than \Code{0}
 *
 * \return \herr_t
 *
 * \return Failure Modes:
 *         - When the user sets the number of read attempts to \Code{0}.
 *         - When the input property list is not a file access property list.
 *         - When the library is unable to set the number of read attempts in the file access property list.
 *
 * \details H5Pset_metadata_read_attempts() sets the number of reads that the
 *          library will try when reading checksummed metadata in an HDF5 file opened
 *          with SWMR access. When reading such metadata, the library will compare the
 *          checksum computed for the metadata just read with the checksum stored within
 *          the piece of checksum. When performing SWMR operations on a file, the
 *          checksum check might fail when the library reads data on a system that is not
 *          atomic. To remedy such situations, the library will repeatedly read the piece
 *          of metadata until the check passes or finally fails the read when the allowed
 *          number of attempts is reached.
 *
 *          The number of read attempts used by the library will depend on how the file is
 *          opened and whether the user sets the number of read attempts via this routine:

 *          - For a file opened with SWMR access:
 *            - If the user sets the number of attempts to \Code{N}, the library will use \Code{N}.
 *            - If the user does not set the number of attempts, the library will use the
 *              default for SWMR access (\Code{100}).
 *          - For a file opened with non-SWMR access, the library will always use the default
 *            for non-SWMR access (\Code{1}). The value set via this routine does not have any effect
 *            during non-SWMR access.
 *
 * \b Example: The first example illustrates the case in setting the number of read attempts for a file
 *             opened with SWMR access.
 *
 * \snippet H5Pset_metadata_read_attempts.c SWMR Access
 *
 * \b Example: The second example illustrates the case in setting the number of
 *             read attempts for a file opened with non-SWMR access. The value
 *             set in the file access property list does not have any effect.
 *
 * \snippet H5Pset_metadata_read_attempts.c non-SWMR Access
 *
 * \note \b Motivation: On a system that is not atomic, the library might
 *       possibly read inconsistent metadata with checksum when performing
 *       single-writer/multiple-reader (SWMR) operations for an HDF5 file. Upon
 *       encountering such situations, the library will try reading the metadata
 *       again to obtain consistent data. This routine provides the means to set
 *       the number of read attempts other than the library default.
 *
 * \since 1.10.0
 */
H5_DLL herr_t H5Pset_metadata_read_attempts(hid_t plist_id, unsigned attempts);
/**
 * \ingroup FAPL
 *
 * \brief Specifies type of data to be accessed via the \Code{MULTI} driver,
 *        enabling more direct access
 *
 * \fapl_id{fapl_id}
 * \param[in] type Type of data to be accessed
 *
 * \return \herr_t
 *
 * \details H5Pset_multi_type() sets the \Emph{type of data} property in the file
 *          access property list \p fapl_id. This setting enables a user
 *          application to specify the type of data the application wishes to
 *          access so that the application can retrieve a file handle for
 *          low-level access to the particular member of a set of \Code{MULTI}
 *          files in which that type of data is stored. The file handle is
 *          retrieved with a separate call to H5Fget_vfd_handle() (or, in special
 *          circumstances, to H5FDget_vfd_handle(); see \ref VFL.
 *
 * The type of data specified in \p type may be one of the following:
 *
 * <table>
 *   <tr>
 *     <td>#H5FD_MEM_SUPER</td>    <td>Super block data</td>
 *   </tr>
 *   <tr>
 *     <td>#H5FD_MEM_BTREE</td>    <td>B-tree data</td>
 *   </tr>
 *   <tr>
 *     <td>#H5FD_MEM_DRAW</td>    <td>Dataset raw data</td>
 *   </tr>
 *   <tr>
 *     <td>#H5FD_MEM_GHEAP</td>    <td>Global heap data</td>
 *   </tr>
 *   <tr>
 *     <td>#H5FD_MEM_LHEAP</td>    <td>Local Heap data</td>
 *   </tr>
 *   <tr>
 *     <td>#H5FD_MEM_OHDR</td>    <td>Object header data</td>
 *   </tr>
 * </table>
 *
 * This function is for use only when accessing an HDF5 file written as a set of
 * files with the \Code{MULTI} file driver.
 *
 * \since 1.6.0
 */
H5_DLL herr_t H5Pset_multi_type(hid_t fapl_id, H5FD_mem_t type);
/**
 * \ingroup FAPL
 *
 * \brief Sets a callback function to invoke when an object flush occurs in the file
 *
 * \fapl_id{plist_id}
 * \op{func}
 * \op_data_in{udata}
 *
 * \return \herr_t
 *
 * \details H5Pset_object_flush_cb() sets the callback function to invoke in the
 *          file access property list \p plist_id whenever an object flush occurs in
 *          the file. Library objects are group, dataset, and committed
 *          datatype.
 *
 *          The callback function \p func must conform to the prototype defined below:
 *          \code
 *          typedef herr_t (*H5F_flush_cb_t)(hid_t object_id, void *user_data)
 *          \endcode
 *
 *          The parameters of the callback function, per the above prototypes, are defined as follows:
 *            - \Code{object_id} is the identifier of the object which has just been flushed.
 *            - \Code{user_data} is the user-defined input data for the callback function.
 *
 * \b Example: The example below illustrates the usage of this routine to set
 *             the callback function to invoke when an object flush occurs.
 *
 * \include H5Pset_object_flush_cb.c
 *
 * \since 1.10.0
 */
H5_DLL herr_t H5Pset_object_flush_cb(hid_t plist_id, H5F_flush_cb_t func, void *udata);
/**
 * \ingroup FAPL
 *
 * \brief Sets the maximum size of the data sieve buffer
 *
 * \fapl_id{fapl_id}
 * \param[in] size Maximum size, in bytes, of data sieve buffer
 *
 * \return \herr_t
 *
 * \details H5Pset_sieve_buf_size() sets \p size, the maximum size in bytes of the
 *          data sieve buffer, which is used by file drivers that are capable of
 *          using data sieving.
 *
 *          The data sieve buffer is used when performing I/O on datasets in the
 *          file. Using a buffer which is large enough to hold several pieces of
 *          the dataset being read in for hyperslab selections boosts
 *          performance by quite a bit.
 *
 *          The default value is set to 64KB, indicating that file I/O for raw
 *          data reads and writes will occur in at least 64KB blocks. Setting
 *          the value to zero (\Code{0}) with this API function will turn off
 *          the data sieving, even if the VFL driver attempts to use that
 *          strategy.
 *
 *          Internally, the library checks the storage sizes of the datasets in
 *          the file. It picks the smaller one between the size from the file
 *          access property and the size of the dataset to allocate the sieve
 *          buffer for the dataset in order to save memory usage.
 *
 * \version 1.6.0 The \p size parameter has changed from type \Code{hsize_t} to \Code{size_t}.
 *
 * \since 1.4.0
 */
H5_DLL herr_t H5Pset_sieve_buf_size(hid_t fapl_id, size_t size);
/**
 * \ingroup FAPL
 *
 * \brief Sets the size of a contiguous block reserved for small data
 *
 * \fapl_id{fapl_id}
 * \param[in] size Maximum size, in bytes, of the small data block.
                   The default size is \Code{2048}.
 *
 * \return \herr_t
 *
 * \details H5Pset_small_data_block_size() reserves blocks of \p size bytes for the
 *          contiguous storage of the raw data portion of \Emph{small} datasets. The
 *          HDF5 library then writes the raw data from small datasets to this
 *          reserved space, thus reducing unnecessary discontinuities within
 *          blocks of meta data and improving I/O performance.
 *
 *          A small data block is actually allocated the first time a qualifying
 *          small dataset is written to the file. Space for the raw data portion
 *          of this small dataset is suballocated within the small data block.
 *          The raw data from each subsequent small dataset is also written to
 *          the small data block until it is filled; additional small data
 *          blocks are allocated as required.
 *
 *          The HDF5 library employs an algorithm that determines whether I/O
 *          performance is likely to benefit from the use of this mechanism with
 *          each dataset as storage space is allocated in the file. A larger
 *          \p size will result in this mechanism being employed with larger
 *          datasets.
 *
 *          The small data block size is set as an allocation property in the
 *          file access property list identified by \p fapl_id.
 *
 *          Setting \p size to zero (\Code{0}) disables the small data block mechanism.
 *
 * \since 1.4.4
 */
H5_DLL herr_t H5Pset_small_data_block_size(hid_t fapl_id, hsize_t size);
/**
 * \ingroup FAPL
 *
 * \brief Set the file VOL connector for a file access property list
 *
 * \fapl_id{plist_id}
 * \param[in]  new_vol_id     VOL connector identifier
 * \param[in]  new_vol_info   Optional VOL information
 *
 * \return \herr_t
 *
 * \details H5Pset_vol() sets the VOL connector \p new_vol_id for a file access
 *          property list \p plist_id using the (optional) VOL information in
 *          \p new_vol_info.
 *
 * \since 1.12.0
 *
 */
H5_DLL herr_t H5Pset_vol(hid_t plist_id, hid_t new_vol_id, const void *new_vol_info);

#ifdef H5_HAVE_PARALLEL
/**
 * \ingroup GACPL
 *
 * \brief Sets metadata I/O mode for read operations to collective or independent (default)
 *
 * \gacpl_id
 * \param[in] is_collective Boolean value indicating whether metadata reads are collective
 *                          (\Code{1}) or independent (\Code{0}).
 *                          Default mode: Independent (\Code{0})
 *
 * \return \herr_t
 *
 * \details H5Pset_all_coll_metadata_ops() sets the metadata I/O mode for read
 *          operations in the access property list \p plist_id.
 *
 *          When engaging in parallel I/O, all metadata write operations must be
 *          collective. If \p is_collective is \Code{1}, this property specifies
 *          that the HDF5 library will perform all metadata read operations
 *          collectively; if \p is_collective is \Code{0}, such operations may
 *          be performed independently.
 *
 *          Users must be aware that several HDF5 operations can potentially
 *          issue metadata reads. These include opening a dataset, datatype, or
 *          group; reading an attribute; or issuing a \Emph{get info} call such
 *          as getting information for a group with H5Fget_info(). Collective
 *          I/O requirements must be kept in mind when issuing such calls in the
 *          context of parallel I/O.
 *
 *          If this property is collective on a file access property list that
 *          is used in creating or opening a file, then the HDF5 library will
 *          assume that all metadata read operations issued on that file
 *          identifier will be issued collectively from all ranks irrespective
 *          of the individual setting of a particular operation. If this
 *          assumption is not adhered to, corruption will be introduced in the
 *          metadata cache and HDF5’s behavior will be undefined.
 *
 *          Alternatively, a user may wish to avoid setting this property
 *          globally on the file access property list, and individually set it
 *          on particular object access property lists (dataset, group, link,
 *          datatype, attribute access property lists) for certain operations.
 *          This will indicate that only the operations issued with such an
 *          access property list will be called collectively and other
 *          operations may potentially be called independently. There are,
 *          however, several HDF5 operations that can issue metadata reads but
 *          have no property list in their function signatures to allow passing
 *          the collective requirement property. For those operations, the only
 *          option is to set the global collective requirement property on the
 *          file access property list; otherwise the metadata reads that can be
 *          triggered from those operations will be done independently by each
 *          process.
 *
 *          Functions that do not accommodate an access property list but that
 *          might issue metadata reads are listed in \ref maybe_metadata_reads.
 *
 * \attention As noted above, corruption will be introduced into the metadata
 *            cache and HDF5 library behavior will be undefined when both of the following
 *            conditions exist:
 *              - A file is created or opened with a file access property list in which the
 *                collective metadata I/O property is set to \Code{1}.
 *              - Any function is called that triggers an independent metadata read while the
 *                file remains open with that file access property list.
 *
 * \attention An approach that avoids this corruption risk is described above.
 *
 * \sa_metadata_ops
 *
 * \since 1.10.0
 */
H5_DLL herr_t H5Pset_all_coll_metadata_ops(hid_t plist_id, hbool_t is_collective);
/**
 * \ingroup GACPL
 *
 * \brief Retrieves metadata read mode setting
 *
 * \gacpl_id
 * \param[out] is_collective Pointer to a buffer containing the Boolean value indicating whether metadata
 *                           reads are collective (\Code{>0}) or independent (\Code{0}).
 *                           Default mode: Independent (\Code{0})
 *
 * \return \herr_t
 *
 * \details H5Pget_all_coll_metadata_ops() retrieves the collective metadata read setting from the access
 *          property list \p plist_id into \p is_collective.
 *
 * \sa_metadata_ops
 *
 * \since 1.10.0
 */
H5_DLL herr_t H5Pget_all_coll_metadata_ops(hid_t plist_id, hbool_t *is_collective);
/**
 * \ingroup FAPL
 *
 * \brief Sets metadata write mode to collective or independent (default)
 *
 * \fapl_id{plist_id}
 * \param[out] is_collective Boolean value indicating whether metadata
 *             writes are collective (\Code{>0}) or independent (\Code{0}).
 *             \Emph{Default mode:} Independent (\Code{0})
 * \return \herr_t
 *
 * \details H5Pset_coll_metadata_write() tells the HDF5 library whether to
 *          perform metadata writes collectively (1) or independently (0).
 *
 *          If collective access is selected, then on a flush of the metadata
 *          cache, all processes will divide the metadata cache entries to be
 *          flushed evenly among themselves and issue a single MPI-IO collective
 *          write operation. This is the preferred method when the size of the
 *          metadata created by the application is large.
 *
 *          If independent access is selected, the library uses the default
 *          method for doing metadata I/O either from process zero or
 *          independently from each process.
 *
 * \sa_metadata_ops
 *
 * \since 1.10.0
 */
H5_DLL herr_t H5Pset_coll_metadata_write(hid_t plist_id, hbool_t is_collective);
/**
 * \ingroup FAPL
 *
 * \brief Retrieves metadata write mode setting
 *
 * \fapl_id{plist_id}
 * \param[out] is_collective Pointer to a boolean value indicating whether
 *             metadata writes are collective (\Code{>0}) or independent (\Code{0}).
 *             \Emph{Default mode:} Independent (\Code{0})
 * \return \herr_t
 *
 * \details H5Pget_coll_metadata_write() retrieves the collective metadata write
 *          setting from the file access property into \p is_collective.
 *
 * \sa_metadata_ops
 *
 * \since 1.10.0
 */
H5_DLL herr_t H5Pget_coll_metadata_write(hid_t plist_id, hbool_t *is_collective);

/**
 * \todo Add missing documentation
 */
H5_DLL herr_t H5Pget_mpi_params(hid_t fapl_id, MPI_Comm *comm, MPI_Info *info);

/**
 * \todo Add missing documentation
 */
H5_DLL herr_t H5Pset_mpi_params(hid_t fapl_id, MPI_Comm comm, MPI_Info info);
#endif /* H5_HAVE_PARALLEL */
/**
 * \ingroup FAPL
 *
 * \brief Sets the metadata cache image option for a file access property list
 *
 * \fapl_id{plist_id}
 * \param[out] config_ptr Pointer to metadata cache image configuration values
 * \return \herr_t
 *
 * \details H5Pset_mdc_image_config() sets the metadata cache image option with
 *          configuration values specified by \p config_ptr for the file access
 *          property list specified in \p plist_id.
 *
 *          #H5AC_cache_image_config_t is defined as follows:
 *          \snippet H5ACpublic.h H5AC_cache_image_config_t_snip
 *          \click4more
 *
 * \par Limitations: While it is an obvious error to request a cache image when
 *      opening the file read only, it is not in general possible to test for
 *      this error in the H5Pset_mdc_image_config() call. Rather than fail the
 *      subsequent file open, the library silently ignores the file image
 *      request in this case.\n It is also an error to request a cache image on
 *      a file that does not support superblock extension messages (i.e. a
 *      superblock version less than 2). As above, it is not always possible to
 *      detect this error in the H5Pset_mdc_image_config() call, and thus the
 *      request for a cache image will fail silently in this case as well.\n
 *      Creation of cache images is currently disabled in parallel -- as above,
 *      any request for a cache image in this context will fail silently.\n
 *      Files with cache images may be read in parallel applications, but note
 *      that the load of the cache image is a collective operation triggered by
 *      the first operation that accesses metadata after file open (or, if
 *      persistent free space managers are enabled, on the first allocation or
 *      deallocation of file space, or read of file space manager status,
 *      whichever comes first). Thus the parallel process may deadlock if any
 *      process does not participate in this access.\n
 *      In long sequences of file  closes and opens, infrequently accessed
 *      metadata can accumulate in the cache image to the point where the cost
 *      of storing and restoring this metadata exceeds the benefit of retaining
 *      frequently used metadata in the cache image. When implemented, the
 *      #H5AC_cache_image_config_t::entry_ageout should address this problem. In
 *      the interim, not requesting a cache image every n file close/open cycles
 *      may be an acceptable work around. The choice of \c n will be driven by
 *      application behavior, but \Code{n = 10} seems a good starting point.
 *
 * \since 1.10.1
 */
H5_DLL herr_t H5Pset_mdc_image_config(hid_t plist_id, H5AC_cache_image_config_t *config_ptr);
/**
 * \ingroup FAPL
 *
 * \brief Sets the maximum size for the page buffer and the minimum percentage
 *        for metadata and raw data pages
 *
 * \fapl_id{plist_id}
 * \param[in] buf_size Maximum size, in bytes, of the page buffer
 * \param[in] min_meta_per Minimum metadata percentage to keep in the page buffer
 *            before allowing pages containing metadata to be evicted (Default is 0)
 * \param[in] min_raw_per Minimum raw data percentage to keep in the page buffer
 *            before allowing pages containing raw data to be evicted (Default is 0)
 * \return \herr_t
 *
 * \details H5Pset_page_buffer_size() sets buf_size, the maximum size in bytes
 *          of the page buffer. The default value is zero, meaning that page
 *          buffering is disabled. When a non-zero page buffer size is set, the
 *          library will enable page buffering if that size is larger or equal
 *          than a single page size if a paged file space strategy is enabled
 *          using the functions H5Pset_file_space_strategy() and
 *          H5Pset_file_space_page_size().
 *
 *          The page buffer layer captures all I/O requests before they are
 *          issued to the VFD and "caches" them in fixed sized pages. Once the
 *          total number of pages exceeds the page buffer size, the library
 *          evicts pages from the page buffer by writing them to the VFD. At
 *          file close, the page buffer is flushed writing all the pages to the
 *          file.
 *
 *          If a non-zero page buffer size is set, and the file space strategy
 *          is not set to paged or the page size for the file space strategy is
 *          larger than the page buffer size, the subsequent call to H5Fcreate()
 *          or H5Fopen() using the \p plist_id will fail.
 *
 *          The function also allows setting the minimum percentage of pages for
 *          metadata and raw data to prevent a certain type of data to evict hot
 *          data of the other type.
 *
 * \since 1.10.1
 *
 */
H5_DLL herr_t H5Pset_page_buffer_size(hid_t plist_id, size_t buf_size, unsigned min_meta_per,
                                      unsigned min_raw_per);

/* Dataset creation property list (DCPL) routines */
/**
 * \ingroup DCPL
 *
 * \brief Determines whether fill value is defined
 *
 * \dcpl_id{plist}
 * \param[out] status Status of fill value in property list
 *
 * \return \herr_t
 *
 * \details H5Pfill_value_defined() determines whether a fill value is
 *          defined in the dataset creation property list \p plist. Valid
 *          values returned in status are as follows:
 *
 *          <table>
 *           <tr>
 *            <td>#H5D_FILL_VALUE_UNDEFINED</td>
 *            <td>Fill value is undefined.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_FILL_VALUE_DEFAULT</td>
 *            <td>Fill value is the library default.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_FILL_VALUE_USER_DEFINED</td>
 *            <td>Fill value is defined by the application.</td>
 *           </tr>
 *          </table>
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pfill_value_defined(hid_t plist, H5D_fill_value_t *status);
/**
 * \ingroup DCPL
 *
 * \brief Retrieves the timing for storage space allocation
 *
 * \dcpl_id{plist_id}
 * \param[out] alloc_time The timing setting for allocating dataset
 *                        storage space
 *
 * \return \herr_t
 *
 * \details H5Pget_alloc_time() retrieves the timing for allocating storage
 *          space for a dataset's raw data. This property is set in the
 *          dataset creation property list \p plist_id. The timing setting
 *          is returned in \p alloc_time as one of the following values:
 *
 *          <table>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_DEFAULT<br />&nbsp;</td>
 *            <td>Uses the default allocation time, based on the dataset
 *                storage method. <br />See the \p alloc_time description in
 *                H5Pset_alloc_time() for default allocation times for
 *                various storage methods.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_EARLY</td>
 *            <td>All space is allocated when the dataset is created.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_INCR</td>
 *            <td>Space is allocated incrementally as data is written
 *                to the dataset.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_LATE</td>
 *            <td>All space is allocated when data is first written to
 *                the dataset.</td>
 *           </tr>
 *          </table>
 *
 * \note H5Pget_alloc_time() is designed to work in concert with the
 *       dataset fill value and fill value write time properties, set
 *       with the functions H5Pget_fill_value() and H5Pget_fill_time().
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pget_alloc_time(hid_t plist_id, H5D_alloc_time_t *alloc_time /*out*/);
/**
 * \ingroup DCPL
 *
 * \brief Retrieves the size of chunks for the raw data of a chunked
 *        layout dataset
 *
 * \dcpl_id{plist_id}
 * \param[in]  max_ndims Size of the \p dims array
 * \param[out] dim Array to store the chunk dimensions
 *
 * \return Returns chunk dimensionality if successful;
 *         otherwise returns a negative value.
 *
 * \details H5Pget_chunk() retrieves the size of chunks for the raw data
 *          of a chunked layout dataset. This function is only valid for
 *          dataset creation property lists. At most, \p max_ndims elements
 *          of \p dim will be initialized.
 *
 * \since 1.0.0
 *
 */
H5_DLL int H5Pget_chunk(hid_t plist_id, int max_ndims, hsize_t dim[] /*out*/);
/**
 *
 * \ingroup DCPL
 *
 * \brief Retrieves the edge chunk option setting from a dataset creation
 *        property list
 *
 * \dcpl_id{plist_id}
 * \param[out] opts  Edge chunk option flag. Valid values are described in
 *                   H5Pset_chunk_opts(). The option status can be
 *                   retrieved using the bitwise AND operator ( & ). For
 *                   example, the expression
 *                   (opts&#H5D_CHUNK_DONT_FILTER_PARTIAL_CHUNKS) will
 *                   evaluate to #H5D_CHUNK_DONT_FILTER_PARTIAL_CHUNKS if
 *                   that option has been enabled. Otherwise, it will
 *                   evaluate to 0 (zero).
 *
 * \return \herr_t
 *
 * \details H5Pget_chunk_opts() retrieves the edge chunk option setting
 *          stored in the dataset creation property list \p plist_id.
 *
 * \since 1.10.0
 *
 */
H5_DLL herr_t H5Pget_chunk_opts(hid_t plist_id, unsigned *opts);
/**
 * \ingroup DCPL
 *
 * \brief Retrieves the setting for whether or not to create minimized
 *        dataset object headers
 *
 * \dcpl_id
 * \param[out] minimize  Flag indicating whether the library will or will
 *                       not create minimized dataset object headers
 *
 * \return \herr_t
 *
 * \details H5Pget_dset_no_attrs_hint() retrieves the
 *          <i>no dataset attributes</i> hint setting for the dataset
 *          creation property list \p dcpl_id. This setting is used to
 *          inform the library to create minimized dataset object headers
 *          when TRUE. The setting value is returned in the boolean pointer
 *          \p minimize.
 *
 * \since 1.10.5
 *
 */
H5_DLL herr_t H5Pget_dset_no_attrs_hint(hid_t dcpl_id, hbool_t *minimize);
/**
 * \ingroup DCPL
 *
 * \brief Returns information about an external file
 *
 * \dcpl_id{plist_id}
 * \param[in]  idx       External file index
 * \param[in]  name_size Maximum length of \p name array
 * \param[out] name      Name of the external file
 * \param[out] offset    Pointer to a location to return an offset value
 * \param[out] size      Pointer to a location to return the size of the
 *                       external file data
 *
 * \return \herr_t
 *
 * \details H5Pget_external() returns information about an external file.
 *          The external file is specified by its index, \p idx, which
 *          is a number from zero to N-1, where N is the value returned
 *          by H5Pget_external_count(). At most \p name_size characters
 *          are copied into the \p name array. If the external file name
 *          is longer than \p name_size with the null terminator, the
 *          return value is not null terminated (similar to strncpy()).
 *
 *          If \p name_size is zero or \p name is the null pointer, the
 *          external file name is not returned. If \p offset or \p size
 *          are null pointers then the corresponding information is not
 *          returned.
 *
 * \version 1.6.4 \p idx parameter type changed to unsigned.
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pget_external(hid_t plist_id, unsigned idx, size_t name_size, char *name /*out*/,
                              off_t *offset /*out*/, hsize_t *size /*out*/);
/**
 * \ingroup DCPL
 *
 * \brief Returns the number of external files for a dataset
 *
 * \dcpl_id{plist_id}
 *
 * \return Returns the number of external files if successful; otherwise
 *         returns a negative value.
 *
 * \details H5Pget_external_count() returns the number of external files
 *          for the specified dataset.
 *
 * \since 1.0.0
 *
 */
H5_DLL int H5Pget_external_count(hid_t plist_id);
/**
 * \ingroup DCPL
 *
 * \brief Retrieves the time when fill values are written to a dataset
 *
 * \dcpl_id{plist_id}
 * \param[out] fill_time Setting for the timing of writing fill values to
 *                       the dataset
 *
 * \return \herr_t
 *
 * \details H5Pget_fill_time() examines the dataset creation property list
 *          \p plist_id to determine when fill values are to be written to
 *          a dataset. Valid values returned in \p fill_time are as
 *          follows:
 *
 *          <table>
 *           <tr>
 *            <td>#H5D_FILL_TIME_IFSET</td>
 *            <td>Fill values are written to the dataset when storage
 *                space is allocated only if there is a user-defined fill
 *                value, i.e., one set with H5Pset_fill_value(). (Default)
 *             </td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_FILL_TIME_ALLOC</td>
 *            <td>Fill values are written to the dataset when storage
 *                space is allocated.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_FILL_TIME_NEVER</td>
 *            <td>Fill values are never written to the dataset.</td>
 *           </tr>
 *          </table>
 *
 * \note H5Pget_fill_time() is designed to work in coordination with the
 *       dataset fill value and dataset storage allocation time properties,
 *       retrieved with the functions H5Pget_fill_value() and
 *       H5Pget_alloc_time().
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pget_fill_time(hid_t plist_id, H5D_fill_time_t *fill_time /*out*/);
/**
 * \ingroup DCPL
 *
 * \brief Retrieves a dataset fill value
 *
 * \dcpl_id{plist_id}
 * \param[in]  type_id Datatype identifier for the value passed via
 *                     \p value
 * \param[out] value   Pointer to buffer to contain the returned
 *                     fill value
 *
 * \return \herr_t
 *
 * \details H5Pget_fill_value() returns the dataset fill value defined in
 *          the dataset creation property list \p plist_id. The fill value
 *          is returned through the \p value pointer and will be converted
 *          to the datatype specified  by \p type_id. This datatype may
 *          differ from the fill value datatype in the property list, but
 *          the HDF5 library must be able to convert between the two
 *          datatypes.
 *
 *          If the fill value is undefined, i.e., set to NULL in the
 *          property list, H5Pget_fill_value() will return an error.
 *          H5Pfill_value_defined() should be used to check for this
 *          condition before H5Pget_fill_value() is called.
 *
 *          Memory must be allocated by the calling application.
 *
 * \note H5Pget_fill_value() is designed to coordinate with the dataset
 *       storage allocation time and fill value write time properties,
 *       which can be retrieved with the functions H5Pget_alloc_time()
 *       and H5Pget_fill_time(), respectively.
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pget_fill_value(hid_t plist_id, hid_t type_id, void *value /*out*/);
/**
 * \ingroup DCPL
 *
 * \brief Returns the layout of the raw data for a dataset
 *
 * \dcpl_id{plist_id}
 *
 * \return Returns the layout type (a non-negative value) of a dataset
 *         creation property list if successful. Valid return values are:
 *         - #H5D_COMPACT: Raw data is stored in the object header in the
 *                        file.
 *         - #H5D_CONTIGUOUS: Raw data is stored separately from the object
 *                           header in one contiguous chunk in the file.
 *         - #H5D_CHUNKED: Raw data is stored separately from the object
 *                        header in chunks in separate locations in the
 *                        file.
 *         - #H5D_VIRTUAL: Raw data is drawn from multiple datasets in
 *                        different files.
 * \return
 *         Otherwise, returns a negative value indicating failure.
 *
 * \details H5Pget_layout() returns the layout of the raw data for a
 *          dataset. This function is only valid for dataset creation
 *          property lists.
 *
 *          Note that a compact storage layout may affect writing data to
 *          the dataset with parallel applications. See the H5Dwrite()
 *          documentation for details.
 *
 * \version 1.10.0 #H5D_VIRTUAL added in this release.
 *
 * \since 1.0.0
 *
 */
H5_DLL H5D_layout_t H5Pget_layout(hid_t plist_id);
/**
 * \ingroup DCPL
 *
 * \brief Gets the number of mappings for the virtual dataset
 *
 * \dcpl_id
 * \param[out] count The number of mappings
 *
 * \return \herr_t
 *
 * \details H5Pget_virtual_count() gets the number of mappings for a
 *          virtual dataset that has the creation property list specified
 *          by \p dcpl_id.
 *
 * \see_virtual
 *
 * \since 1.10.0
 *
 */
H5_DLL herr_t H5Pget_virtual_count(hid_t dcpl_id, size_t *count /*out*/);
/**
 * \ingroup DCPL
 *
 * \brief Gets the name of a source dataset used in the mapping
 *
 * \dcpl_id
 * \param[in]  index Mapping index. The value of \p index is 0 (zero) or
 *                   greater and less than \p count
 *                   (0 ≤ \p index < \p count), where \p count is the
 *                   number of mappings returned by H5Pget_virtual_count().
 * \param[out] name  A buffer containing the name of the source dataset
 * \param[in]  size  The size, in bytes, of the name buffer. Must be the
 *                   size of the dataset name in bytes plus 1 for a NULL
 *                   terminator
 *
 * \return Returns the length of the dataset name if successful;
 *         otherwise returns a negative value.
 *
 * \details H5Pget_virtual_dsetname() takes the dataset creation property
 *          list for the virtual dataset, \p dcpl_id, the mapping index,
 *          \p index, the size of the dataset name for a source dataset,
 *          \p size, and retrieves the name of the source dataset used in
 *          the mapping.
 *
 *          Up to \p size characters of the dataset name are returned in
 *          \p name; additional characters, if any, are not returned to
 *          the user application.
 *
 *          If the length of the dataset name, which determines the
 *          required value of \p size, is unknown, a preliminary call
 *          to H5Pget_virtual_dsetname() with the last two parameters
 *          set to NULL and zero respectively can be made. The return
 *          value of this call will be the size in bytes of the dataset
 *          name. That value, plus 1 for a NULL terminator, must then be
 *          assigned to \p size for a second H5Pget_virtual_dsetname()
 *          call, which will retrieve the actual dataset name.
 *
 * \see_virtual
 *
 * \since 1.10.0
 *
 */
H5_DLL ssize_t H5Pget_virtual_dsetname(hid_t dcpl_id, size_t index, char *name /*out*/, size_t size);
/**
 * \ingroup DCPL
 *
 * \brief Gets the filename of a source dataset used in the mapping
 *
 * \dcpl_id
 * \param[in]  index Mapping index. The value of \p index is 0 (zero) or
 *                   greater and less than \p count
 *                   (0 ≤ \p index < \p count), where \p count is the
 *                   number of mappings returned by H5Pget_virtual_count().
 * \param[out] name  A buffer containing the name of the file containing
 *                   the source dataset
 * \param[in]  size  The size, in bytes, of the name buffer. Must be the
 *                   size of the filename in bytes plus 1 for a NULL
 *                   terminator
 *
 * \return Returns the length of the filename if successful; otherwise
 *         returns a negative value.
 *
 * \details H5Pget_virtual_filename() takes the dataset creation property
 *          list for the virtual dataset, \p dcpl_id, the mapping index,
 *          \p index, the size of the filename for a source dataset,
 *          \p size, and retrieves the name of the file for a source dataset
 *          used in the mapping.
 *
 *          Up to \p size characters of the filename are returned in
 *          \p name; additional characters, if any, are not returned to
 *          the user application.
 *
 *          If the length of the filename, which determines the required
 *          value of \p size, is unknown, a preliminary call to
 *          H5Pget_virtual_filename() with the last two parameters set
 *          to NULL and zero respectively can be made. The return value
 *          of this call will be the size in bytes of the filename. That
 *          value, plus 1 for a NULL terminator, must then be assigned to
 *          \p size for a second H5Pget_virtual_filename() call, which
 *          will retrieve the actual filename.
 *
 * \see_virtual
 *
 * \since 1.10.0
 *
 */
H5_DLL ssize_t H5Pget_virtual_filename(hid_t dcpl_id, size_t index, char *name /*out*/, size_t size);
/**
 * \ingroup DCPL
 *
 * \brief Gets a dataspace identifier for the selection within the source
 *        dataset used in the mapping
 *
 * \dcpl_id
 * \param[in] index Mapping index. The value of \p index is 0 (zero) or
 *                  greater and less than \p count
 *                  (0 ≤ \p index < \p count), where \p count is the number
 *                  of mappings returned by H5Pget_virtual_count().
 *
 * \return \hid_t{valid dataspace identifier}
 *
 * \details H5Pget_virtual_srcspace() takes the dataset creation property
 *          list for the virtual dataset, \p dcpl_id, and the mapping
 *          index, \p index, and returns a dataspace identifier for the
 *          selection within the source dataset used in the mapping.
 *
 * \see_virtual
 *
 * \since 1.10.0
 *
 */
H5_DLL hid_t H5Pget_virtual_srcspace(hid_t dcpl_id, size_t index);
/**
 * \ingroup DCPL
 *
 * \brief Gets a dataspace identifier for the selection within the virtual
 *        dataset used in the mapping
 *
 * \dcpl_id
 * \param[in] index Mapping index. The value of \p index is 0 (zero) or
 *                  greater and less than \p count
 *                  (0 ≤ \p index < \p count), where \p count is the number
 *                  of mappings returned by H5Pget_virtual_count()
 *
 * \return \hid_t{valid dataspace identifier}
 *
 * \details H5Pget_virtual_vspace() takes the dataset creation property
 *          list for the virtual dataset, \p dcpl_id, and the mapping
 *          index, \p index, and returns a dataspace identifier for the
 *          selection within the virtual dataset used in the mapping.
 *
 * \see_virtual
 *
 * \since 1.10.0
 *
 */
H5_DLL hid_t H5Pget_virtual_vspace(hid_t dcpl_id, size_t index);
/**
 * \ingroup DCPL
 *
 * \brief Sets the timing for storage space allocation
 *
 * \dcpl_id{plist_id}
 * \param[in] alloc_time When to allocate dataset storage space
 *
 * \return \herr_t
 *
 * \details H5Pset_alloc_time() sets up the timing for the allocation of
 *          storage space for a dataset's raw data. This property is set
 *          in the dataset creation property list \p plist_id. Timing is
 *          specified in \p alloc_time with one of the following values:
 *
 *          <table>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_DEFAULT</td>
 *            <td>Allocate dataset storage space at the default time<br />
 *                (Defaults differ by storage method.)</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_EARLY</td>
 *            <td>Allocate all space when the dataset is created<br />
 *            (Default for compact datasets.)</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_INCR</td>
 *            <td>Allocate space incrementally, as data is written to
 *                the dataset<br />(Default for chunked storage datasets.)
 *
 *                \li Chunked datasets: Storage space allocation for each
 *                    chunk is deferred until data is written to the chunk.
 *                \li Contiguous datasets: Incremental storage space
 *                    allocation for contiguous data is treated as late
 *                    allocation.
 *                \li Compact datasets: Incremental allocation is not
 *                    allowed with compact datasets; H5Pset_alloc_time()
 *                    will return an error.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_ALLOC_TIME_LATE</td>
 *            <td>Allocate all space when data is first written to the
 *                dataset<br />
 *                (Default for contiguous datasets.)</td>
 *           </tr>
 *          </table>
 *
 * \note H5Pset_alloc_time() is designed to work in concert with the
 *       dataset fill value and fill value write time properties, set
 *       with the functions H5Pset_fill_value() and H5Pset_fill_time().
 *
 * \note See H5Dcreate() for further cross-references.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pset_alloc_time(hid_t plist_id, H5D_alloc_time_t alloc_time);
/**
 * \ingroup DCPL
 *
 * \brief Sets the size of the chunks used to store a chunked layout
 *        dataset
 *
 * \dcpl_id{plist_id}
 * \param[in] ndims  The number of dimensions of each chunk
 * \param[in] dim    An array defining the size, in dataset elements, of
 *                   each chunk
 *
 * \return \herr_t
 * \details H5Pset_chunk() sets the size of the chunks used to store a
 *          chunked layout dataset. This function is only valid for dataset
 *          creation property lists.
 *
 *          The \p ndims parameter currently must be the same size as the
 *          rank of the dataset.
 *
 *          The values of the \p dim array define the size of the chunks
 *          to store the dataset's raw data. The unit of measure for \p dim
 *          values is dataset elements.
 *
 *          As a side-effect of this function, the layout of the dataset is
 *          changed to #H5D_CHUNKED, if it is not already so set.
 *
 * \note Chunk size cannot exceed the size of a fixed-size dataset. For
 *       example, a dataset consisting of a 5x4 fixed-size array cannot be
 *       defined with 10x10 chunks. Chunk maximums:
 *       - The maximum number of elements in a chunk is 2<sup>32</sup>-1 which
 *         is equal to 4,294,967,295. If the number of elements in a chunk is
 *         set via H5Pset_chunk() to a value greater than 2<sup>32</sup>-1,
 *         then H5Pset_chunk() will fail.
 *       - The maximum size for any chunk is 4GB. If a chunk that is larger
 *         than 4GB attempts to be written with H5Dwrite(), then H5Dwrite()
 *         will fail.
 *
 * \see H5Pset_layout(), H5Dwrite()
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_chunk(hid_t plist_id, int ndims, const hsize_t dim[/*ndims*/]);
/**
 * \ingroup DCPL
 *
 * \brief Sets the edge chunk option in a dataset creation property list
 *
 * \dcpl_id{plist_id}
 * \param[in] opts Edge chunk option flag. Valid values are:
 *                 \li #H5D_CHUNK_DONT_FILTER_PARTIAL_CHUNKS
 *                     When enabled, filters are not applied to partial
 *                     edge chunks. When disabled, partial edge chunks are
 *                     filtered. Enabling this option will improve
 *                     performance when appending to the dataset and, when
 *                     compression filters are used, prevent reallocation
 *                     of these chunks. Datasets created with this option
 *                     enabled will be inaccessible with HDF5 library
 *                     versions before Release 1.10. Default: \e Disabled
 *                 \li 0 (zero) Disables option; partial edge chunks
 *                     will be compressed.
 *
 * \return \herr_t
 *
 * \details H5Pset_chunk_opts() sets the edge chunk option in the
 *          dataset creation property list \p dcpl_id.
 *
 *          The available option is detailed in the parameters section.
 *          Only chunks that are not completely filled by the dataset’s
 *          dataspace are affected by this option. Such chunks are
 *          referred to as partial edge chunks.
 *
 *      \b Motivation: H5Pset_chunk_opts() is used to specify storage
 *       options for chunks on the edge of a dataset’s dataspace. This
 *       capability allows the user to tune performance in cases where
 *       the dataset size may not be a multiple of the chunk size and
 *       the handling of partial edge chunks can impact performance.
 *
 * \since 1.10.0
 *
 */
H5_DLL herr_t H5Pset_chunk_opts(hid_t plist_id, unsigned opts);
/**
 * \ingroup DCPL
 *
 * \brief Sets the flag to create minimized dataset object headers
 *
 * \dcpl_id
 * \param[in] minimize Flag for indicating whether or not a dataset's
 *                     object header will be minimized
 *
 * \return \herr_t
 *
 * \details H5Pset_dset_no_attrs_hint() sets the no dataset attributes
 *          hint setting for the dataset creation property list \p dcpl_id.
 *          Datasets created with the dataset creation property list
 *          \p dcpl_id will have their object headers minimized if the
 *          boolean flag \p minimize is set to TRUE. By setting \p minimize
 *          to TRUE, the library expects that no attributes will be added
 *          to the dataset. Attributes can be added, but they are appended
 *          with a continuation message, which can reduce performance.
 *
 *          This setting interacts with H5Fset_dset_no_attrs_hint(): if
 *          either is set to TRUE, then the created dataset's object header
 *          will be minimized.
 *
 * \since 1.10.5
 *
 */
H5_DLL herr_t H5Pset_dset_no_attrs_hint(hid_t dcpl_id, hbool_t minimize);
/**
 * \ingroup DCPL
 *
 * \brief Adds an external file to the list of external files
 *
 * \dcpl_id{plist_id}
 * \param[in] name   Name of an external file
 * \param[in] offset Offset, in bytes, from the beginning of the file to
 *                   the location in the file where the data starts
 * \param[in] size   Number of bytes reserved in the file for the data
 *
 * \return \herr_t
 *
 * \details The first call to H5Pset_external() sets the external
 *          storage property in the property list, thus designating that
 *          the dataset will be stored in one or more non-HDF5 file(s)
 *          external to the HDF5 file. This call also adds the file
 *          \p name as the first file in the list of external files.
 *          Subsequent calls to the function add the named file as the
 *          next file in the list.
 *
 *          If a dataset is split across multiple files, then the files
 *          should be defined in order. The total size of the dataset is
 *          the sum of the \p size arguments for all the external files.
 *          If the total size is larger than the size of a dataset then
 *          the dataset can be extended (provided the data space also
 *          allows the extending).
 *
 *         The \p size argument specifies the number of bytes reserved
 *         for data in the external file. If \p size is set to
 *         #H5F_UNLIMITED, the external file can be of unlimited size
 *         and no more files can be added to the external files list.
 *         If \p size is set to 0 (zero), no external file will actually
 *         be created.
 *
 *         All of the external files for a given dataset must be specified
 *         with H5Pset_external() before H5Dcreate() is called to create
 *         the dataset. If one these files does not exist on the system
 *         when H5Dwrite() is called to write data to it, the library
 *         will create the file.
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_external(hid_t plist_id, const char *name, off_t offset, hsize_t size);
/**
 * \ingroup DCPL
 *
 * \brief Sets the time when fill values are written to a dataset
 *
 * \dcpl_id{plist_id}
 * \param[in] fill_time When to write fill values to a dataset
 *
 * \return \herr_t
 *
 * \details H5Pset_fill_time() sets up the timing for writing fill values
 *          to a dataset. This property is set in the dataset creation
 *          property list \p plist_id. Timing is specified in \p fill_time
 *          with one of the following values:
 *
 *          <table>
 *           <tr>
 *            <td>#H5D_FILL_TIME_IFSET</td>
 *            <td>Write fill values to the dataset when storage space is
 *                allocated only if there is a user-defined fill value,
 *                i.e.,one set with H5Pset_fill_value(). (Default)</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_FILL_TIME_ALLOC</td>
 *            <td>Write fill values to the dataset when storage space is
 *                allocated.</td>
 *           </tr>
 *           <tr>
 *            <td>#H5D_FILL_TIME_NEVER</td>
 *            <td>Never write fill values to the dataset.</td>
 *           </tr>
 *          </table>
 *
 * \note H5Pset_fill_time() is designed for coordination with the dataset
 *      fill value and dataset storage allocation time properties, set
 *      with the functions H5Pset_fill_value() and H5Pset_alloc_time().
 *      See H5Dcreate() for further cross-references.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pset_fill_time(hid_t plist_id, H5D_fill_time_t fill_time);
/**
 * \ingroup DCPL
 *
 * \brief Sets the fill value for a dataset
 *
 * \dcpl_id{plist_id}
 * \param[in] type_id Datatype of \p value
 * \param[in] value Pointer to buffer containing value to use as
 *            fill value
 *
 * \return \herr_t
 *
 * \details H5Pset_fill_value() sets the fill value for a dataset in the
 *          dataset creation property list. \p value is interpreted as
 *          being of datatype \p type_id. This datatype may differ from
 *          that of the dataset, but the HDF5 library must be able to
 *          convert \p value to the dataset datatype when the dataset is
 *          created.
 *
 *          The default fill value is 0 (zero), which is interpreted
 *          according to the actual dataset datatype.
 *
 *          Setting \p value to NULL indicates that the fill value is to
 *          be undefined.
 *
 * \note Applications sometimes write data only to portions of an allocated
 *       dataset. It is often useful in such cases to fill the unused space
 *       with a known fill value. This function allows the user application
 *       to set that fill value; the functions H5Dfill() and
 *       H5Pset_fill_time(), respectively, provide the ability to apply the
 *       fill value on demand or to set up its automatic application.
 *
 * \note A fill value should be defined so that it is appropriate for the
 *       application. While the HDF5 default fill value is 0 (zero), it is
 *       often appropriate to use another value. It might be useful, for
 *       example, to use a value that is known to be impossible for the
 *       application to legitimately generate.
 *
 * \note H5Pset_fill_value() is designed to work in concert with
 *       H5Pset_alloc_time() and H5Pset_fill_time(). H5Pset_alloc_time()
 *       and H5Pset_fill_time() govern the timing of dataset storage
 *       allocation and fill value write operations and can be important in
 *       tuning application performance.
 *
 * \note See H5Dcreate() for further cross-references.
 *
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_fill_value(hid_t plist_id, hid_t type_id, const void *value);
/**
 * \ingroup DCPL
 *
 * \brief Sets up use of the shuffle filter
 *
 * \dcpl_id{plist_id}
 *
 * \return \herr_t
 *
 * \details H5Pset_shuffle() sets the shuffle filter, #H5Z_FILTER_SHUFFLE,
 *          in the dataset creation property list \p plist_id. The shuffle
 *          filter de-interlaces a block of data by reordering the bytes.
 *          All the bytes from one consistent byte position of each data
 *          element are placed together in one block; all bytes from a
 *          second consistent byte position of each data element are placed
 *          together a second block; etc. For example, given three data
 *          elements of a 4-byte datatype stored as 012301230123, shuffling
 *          will re-order data as 000111222333. This can be a valuable step
 *          in an effective compression algorithm because the bytes in each
 *          byte position are often closely related to each other and
 *          putting them together can increase the compression ratio.
 *
 *          As implied above, the primary value of the shuffle filter lies
 *          in its coordinated use with a compression filter; it does not
 *          provide data compression when used alone. When the shuffle
 *          filter is applied to a dataset immediately prior to the use of
 *          a compression filter, the compression ratio achieved is often
 *          superior to that achieved by the use of a compression filter
 *          without the shuffle filter.
 *
 * \since 1.6.0
 *
 */
H5_DLL herr_t H5Pset_shuffle(hid_t plist_id);
/**
 * \ingroup DCPL
 *
 * \brief Sets the type of storage used to store the raw data for a dataset
 *
 * \dcpl_id{plist_id}
 * \param[in] layout Type of storage layout for raw data
 *
 * \return \herr_t
 * \details H5Pset_layout() sets the type of storage used to store the raw
 *          data for a dataset. This function is only valid for dataset
 *          creation property lists.
 *
 *          Valid values for \p layout are:
 *           - #H5D_COMPACT: Store raw data in the dataset object header
 *                           in file. This should only be used for datasets
 *                           with small amounts of raw data. The raw data
 *                           size limit is 64K (65520 bytes). Attempting
 *                           to create a dataset with raw data larger than
 *                           this limit will cause the H5Dcreate() call to
 *                           fail.
 *           - #H5D_CONTIGUOUS: Store raw data separately from the object
 *                              header in one large chunk in the file.
 *           - #H5D_CHUNKED: Store raw data separately from the object header
 *                           as chunks of data in separate locations in
 *                           the file.
 *           - #H5D_VIRTUAL: Draw raw data from multiple datasets in
 *                           different files.
 *
 *          Note that a compact storage layout may affect writing data to
 *          the dataset with parallel applications. See the note in
 *          H5Dwrite() documentation for details.
 * \version 1.10.0 #H5D_VIRTUAL added in this release.
 * \since 1.0.0
 *
 */
H5_DLL herr_t H5Pset_layout(hid_t plist_id, H5D_layout_t layout);
/**
 * \ingroup DCPL
 *
 * \brief Sets up the use of the N-Bit filter
 *
 * \dcpl_id{plist_id}
 *
 * \return \herr_t
 *
 * \details H5Pset_nbit() sets the N-Bit filter, #H5Z_FILTER_NBIT, in the
 *          dataset creation property list \p plist_id.
 *
 *          The HDF5 user can create an N-Bit datatype with the following
 *          code:
 *          <pre>
 *          hid_t nbit_datatype = H5Tcopy(H5T_STD_I32LE);
 *          H5Tset_precision(nbit_datatype, 16);
 *          H5Tset_offset(nbit_datatype, 4);
 *          </pre>
 *
 *          In memory, one value of the N-Bit datatype in the above example
 *          will be stored on a little-endian machine as follows:
 *
 *          <table>
 *          <tr>
 *            <td>byte 3</td>
 *            <td>byte 2</td>
 *            <td>byte 1</td>
 *            <td>byte 0</td>
 *          </tr>
 *          <tr>
 *            <td>????????</td>
 *            <td>????SPPP</td>
 *            <td>PPPPPPPP</td>
 *            <td>PPPP????</td>
 *          </tr>
 *          </table>
 *          Note: S - sign bit, P - significant bit, ? - padding bit; For
 *          signed integer, the sign bit is included in the precision.
 *
 *          When data of the above datatype is stored on disk using the
 *          N-bit filter, all padding bits are chopped off and only
 *          significant bits are stored. The values on disk will be
 *          something like:
 *
 *          <table>
 *          <tr>
 *           <td>1st value</td>
 *           <td>2nd value</td>
 *           <td>...</td>
 *          </tr>
 *          <tr>
 *           <td>SPPPPPPPPPPPPPPP</td>
 *           <td>SPPPPPPPPPPPPPPP</td>
 *           <td>...</td>
 *          </tr>
 *          </table>
 *          The N-Bit filter is used effectively for compressing data of
 *          an N-Bit datatype as well as a compound and an array
 *          datatype with N-Bit fields. However, the datatype classes of
 *          the N-Bit datatype or the N-Bit field of the compound
 *          datatype or the array datatype are limited to integer or
 *          floating-point.
 *
 *          The N-Bit filter supports complex situations where a compound
 *          datatype contains member(s) of a compound datatype or an array
 *          datatype that has a compound datatype as the base type.
 *          However, it does not support the situation where an array
 *          datatype has a variable-length or variable-length string as
 *          its base datatype. The filter does support the situation where
 *          a variable-length or variable-length string is a member of a
 *          compound datatype.
 *
 *          The N-Bit filter allows all other HDF5 datatypes (such as
 *          time, string, bitfield, opaque, reference, enum, and variable
 *          length) to pass through as a no-op.
 *
 *          Like other I/O filters supported by the HDF5 library,
 *          application using the N-Bit filter must store data with
 *          chunked storage.
 *
 *          By nature, the N-Bit filter should not be used together with
 *          other I/O filters.
 *
 * \version 1.8.8 Fortran subroutine introduced in this release.
 *
 * \since 1.8.0
 *
 */
H5_DLL herr_t H5Pset_nbit(hid_t plist_id);
/**
 * \ingroup DCPL
 *
 * \brief  Sets up the use of the scale-offset filter
 *
 * \dcpl_id{plist_id}
 * \param[in] scale_type   Flag indicating compression method
 * \param[in] scale_factor Parameter related to scale. Must be
 *                         non-negative
 *
 * \return \herr_t
 *
 * \details H5Pset_scaleoffset() sets the scale-offset filter,
 *          #H5Z_FILTER_SCALEOFFSET, for a dataset.
 *
 *          Generally speaking, scale-offset compression performs a scale and/or
 *          offset operation on each data value and truncates the resulting
 *          value to a minimum number of bits (MinBits) before storing it. The
 *          current scale-offset filter supports integer and floating-point
 *          datatypes.
 *
 *          For an integer datatype, the parameter \p scale_type should be set
 *          to #H5Z_SO_INT (2). The parameter \p scale_factor denotes MinBits.
 *          If the user sets it to H5Z_SO_INT_MINBITS_DEFAULT (0), the filter
 *          will calculate MinBits. If \p scale_factor is set to a positive
 *          integer, the filter does not do any calculation and just uses the
 *          number as MinBits. However, if the user gives a MinBits that is less
 *          than what would be generated by the filter, the compression will be
 *          lossy. Also, the MinBits supplied by the user cannot exceed the
 *          number of bits to store one value of the dataset datatype.
 *
 *          For a floating-point datatype, the filter adopts the GRiB data
 *          packing mechanism, which offers two alternate methods: E-scaling and
 *          D-scaling. Both methods are lossy compression. If the parameter
 *          \p scale_type is set to #H5Z_SO_FLOAT_DSCALE (0), the filter will
 *          use the D-scaling method; if it is set to #H5Z_SO_FLOAT_ESCALE (1),
 *          the filter will use the E-scaling method. Since only the D-scaling
 *          method is implemented, \p scale_type should be set to
 *          #H5Z_SO_FLOAT_DSCALE or 0.
 *
 *          When the D-scaling method is used, the original data is "D" scaled
 *          — multiplied by 10 to the power of \p scale_factor, and the
 *          "significant" part of the value is moved to the left of the decimal
 *          point. Care should be taken in setting the decimal \p scale_factor
 *          so that the integer part will have enough precision to contain the
 *          appropriate information of the data value. For example, if
 *          \p scale_factor is set to 2, the number 104.561 will be 10456.1
 *          after "D" scaling. The last digit 1 is not "significant" and is
 *          thrown off in the process of rounding. The user should make sure that
 *          after "D" scaling and rounding, the data values are within the range
 *          that can be represented by the integer (same size as the
 *          floating-point type).
 *
 *          Valid values for scale_type are as follows:
 *
 *          <table>
 *          <tr>
 *            <td>#H5Z_SO_FLOAT_DSCALE (0)</td>
 *            <td>Floating-point type, using variable MinBits method</td>
 *          </tr>
 *          <tr>
 *            <td>#H5Z_SO_FLOAT_ESCALE (1)</td>
 *            <td>Floating-point type, using fixed MinBits method</td>
 *          </tr>
 *          <tr>
 *            <td>#H5Z_SO_INT (2)</td>
 *            <td>Integer type</td>
 *          </tr>
 *          </table>
 *
 *          The meaning of \p scale_factor varies according to the value
 *          assigned to \p scale_type:
 *
 *          <table>
 *          <tr>
 *            <th>\p scale_type value</th>
 *            <th>\p scale_factor description</th>
 *          </tr>
 *          <tr>
 *            <td>#H5Z_SO_FLOAT_DSCALE</td>
 *            <td>Denotes the decimal scale factor for D-scaling and can be
 *                positive, negative or zero. This is the current
 *                implementation of the library.</td>
 *          </tr>
 *          <tr>
 *            <td>#H5Z_SO_FLOAT_ESCALE</td>
 *            <td>Denotes MinBits for E-scaling and must be a positive integer.
 *                This is not currently implemented by the library.</td>
 *          </tr>
 *          <tr>
 *            <td>#H5Z_SO_INT</td>
 *            <td>Denotes MinB