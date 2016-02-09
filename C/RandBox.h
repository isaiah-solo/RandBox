/**
 * RANDBOX: C Version
 *
 * Created by isayyuhh on 2/7/2016
 */

#ifndef _RANDBOX_
#define _RANDBOX_

/**
 * Struct declarations
 */
typedef struct _RandBox RandBox;
typedef struct _Element Element;

/**
 * Initializes values in RandBox
 *
 * @param rb: Reference to RandBox
 * @return
 */
void randbox_init (RandBox **rb);

/**
 * Returns number of elements in RandBox
 *
 * @param rb: Reference to RandBox
 * @return Integer containing amount of elements in RandBox
 */
int randbox_size (RandBox **rb);

/**
 * Adds one or more elements to the RandBox
 *
 * @param rb: Reference to RandBox
 * @param name: String containing new element to be added
 * @param amount: Amount of elements to be added
 * @return
 */
void randbox_add (RandBox **rb, char *name, int amount);

/**
 * Deletes specified element from RandBox
 *
 * @param rb: Reference to RandBox
 * @param name: Name of element to delete
 * @param amount: Amount of elements to be added
 * @return
 */
void randbox_delete (RandBox **rb, char *name, int amount);

/**
 * Deletes all elements from RandBox
 *
 * @param rb: Reference to RandBox
 * @return
 */
void randbox_delete_all (RandBox **rb);

/**
 * Returns probability of specified element
 *
 * @param rb: Reference to RandBox
 * @param name: Name of element to find probability of
 * @return Float containing probability of element
 */
float randbox_probability (RandBox **rb, char *name);

/**
 * Chooses random element from RandBox
 *
 * @param rb: Reference to RandBox
 * @return Element to be chosen from RandBox
 */
char *randbox_pick (RandBox **rb);

/**
 * Chooses multiple random elements from RandBox
 *
 * @param rb: Reference to RandBox
 * @param choice_list: Reference to array of elements chosen from RandBox
 * @param amount: Amount of elements to be picked
 * @return
 */
void randbox_mult_pick (RandBox **rb, char ***choice_list, int amount);

#endif
