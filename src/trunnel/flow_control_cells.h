/* flow_control_cells.h -- generated by Trunnel v1.5.3.
 * https://gitweb.torproject.org/trunnel.git
 * You probably shouldn't edit this file.
 */
#ifndef TRUNNEL_FLOW_CONTROL_CELLS_H
#define TRUNNEL_FLOW_CONTROL_CELLS_H

#include <stdint.h>
#include "trunnel.h"

#if !defined(TRUNNEL_OPAQUE) && !defined(TRUNNEL_OPAQUE_XOFF_CELL)
struct xoff_cell_st {
  uint8_t version;
  uint8_t trunnel_error_code_;
};
#endif
typedef struct xoff_cell_st xoff_cell_t;
#if !defined(TRUNNEL_OPAQUE) && !defined(TRUNNEL_OPAQUE_XON_CELL)
struct xon_cell_st {
  uint8_t version;
  uint32_t kbps_ewma;
  uint8_t trunnel_error_code_;
};
#endif
typedef struct xon_cell_st xon_cell_t;
/** Return a newly allocated xoff_cell with all elements set to zero.
 */
xoff_cell_t *xoff_cell_new(void);
/** Release all storage held by the xoff_cell in 'victim'. (Do nothing
 * if 'victim' is NULL.)
 */
void xoff_cell_free(xoff_cell_t *victim);
/** Try to parse a xoff_cell from the buffer in 'input', using up to
 * 'len_in' bytes from the input buffer. On success, return the number
 * of bytes consumed and set *output to the newly allocated
 * xoff_cell_t. On failure, return -2 if the input appears truncated,
 * and -1 if the input is otherwise invalid.
 */
ssize_t xoff_cell_parse(xoff_cell_t **output, const uint8_t *input, const size_t len_in);
/** Return the number of bytes we expect to need to encode the
 * xoff_cell in 'obj'. On failure, return a negative value. Note that
 * this value may be an overestimate, and can even be an underestimate
 * for certain unencodeable objects.
 */
ssize_t xoff_cell_encoded_len(const xoff_cell_t *obj);
/** Try to encode the xoff_cell from 'input' into the buffer at
 * 'output', using up to 'avail' bytes of the output buffer. On
 * success, return the number of bytes used. On failure, return -2 if
 * the buffer was not long enough, and -1 if the input was invalid.
 */
ssize_t xoff_cell_encode(uint8_t *output, size_t avail, const xoff_cell_t *input);
/** Check whether the internal state of the xoff_cell in 'obj' is
 * consistent. Return NULL if it is, and a short message if it is not.
 */
const char *xoff_cell_check(const xoff_cell_t *obj);
/** Clear any errors that were set on the object 'obj' by its setter
 * functions. Return true iff errors were cleared.
 */
int xoff_cell_clear_errors(xoff_cell_t *obj);
/** Return the value of the version field of the xoff_cell_t in 'inp'
 */
uint8_t xoff_cell_get_version(const xoff_cell_t *inp);
/** Set the value of the version field of the xoff_cell_t in 'inp' to
 * 'val'. Return 0 on success; return -1 and set the error code on
 * 'inp' on failure.
 */
int xoff_cell_set_version(xoff_cell_t *inp, uint8_t val);
/** Return a newly allocated xon_cell with all elements set to zero.
 */
xon_cell_t *xon_cell_new(void);
/** Release all storage held by the xon_cell in 'victim'. (Do nothing
 * if 'victim' is NULL.)
 */
void xon_cell_free(xon_cell_t *victim);
/** Try to parse a xon_cell from the buffer in 'input', using up to
 * 'len_in' bytes from the input buffer. On success, return the number
 * of bytes consumed and set *output to the newly allocated
 * xon_cell_t. On failure, return -2 if the input appears truncated,
 * and -1 if the input is otherwise invalid.
 */
ssize_t xon_cell_parse(xon_cell_t **output, const uint8_t *input, const size_t len_in);
/** Return the number of bytes we expect to need to encode the
 * xon_cell in 'obj'. On failure, return a negative value. Note that
 * this value may be an overestimate, and can even be an underestimate
 * for certain unencodeable objects.
 */
ssize_t xon_cell_encoded_len(const xon_cell_t *obj);
/** Try to encode the xon_cell from 'input' into the buffer at
 * 'output', using up to 'avail' bytes of the output buffer. On
 * success, return the number of bytes used. On failure, return -2 if
 * the buffer was not long enough, and -1 if the input was invalid.
 */
ssize_t xon_cell_encode(uint8_t *output, size_t avail, const xon_cell_t *input);
/** Check whether the internal state of the xon_cell in 'obj' is
 * consistent. Return NULL if it is, and a short message if it is not.
 */
const char *xon_cell_check(const xon_cell_t *obj);
/** Clear any errors that were set on the object 'obj' by its setter
 * functions. Return true iff errors were cleared.
 */
int xon_cell_clear_errors(xon_cell_t *obj);
/** Return the value of the version field of the xon_cell_t in 'inp'
 */
uint8_t xon_cell_get_version(const xon_cell_t *inp);
/** Set the value of the version field of the xon_cell_t in 'inp' to
 * 'val'. Return 0 on success; return -1 and set the error code on
 * 'inp' on failure.
 */
int xon_cell_set_version(xon_cell_t *inp, uint8_t val);
/** Return the value of the kbps_ewma field of the xon_cell_t in 'inp'
 */
uint32_t xon_cell_get_kbps_ewma(const xon_cell_t *inp);
/** Set the value of the kbps_ewma field of the xon_cell_t in 'inp' to
 * 'val'. Return 0 on success; return -1 and set the error code on
 * 'inp' on failure.
 */
int xon_cell_set_kbps_ewma(xon_cell_t *inp, uint32_t val);


#endif