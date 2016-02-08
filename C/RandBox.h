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
 * Struct containing RandBox contents
 */
struct _RandBox {
   Element *first;
   int size;
};
/**
* Struct containing RandBox elements
*/
struct _Element {
   char *name;
   int amount;
   Element *next;
};

/**
 * Initializes values in RandBox
 *
 * @param rb: Reference to RandBox
 * @return Success or failure
 */
int init_randbox (RandBox *rb); 

/**
 * Adds one or more elements to the RandBox
 *
 * @param rb: Reference to RandBox
 * @param new_name: String containing new element to be added
 * @param new_amount: amount of elements to be added
 * @return Success or failure
 */
int add_randbox_elem (RandBox *rb, char *new_name, int new_amount);

/**
 * Returns number of elements in RandBox
 *
 * @param rb: Reference to RandBox
 * @param size: Integer containing amount of elements in RandBox
 * @return Success or failure
 */
int size_randbox (RandBox *rb, int *size);

/**
 * Chooses random element from RandBox
 *
 * @param rb: Reference to RandBox
 * @param elem: Element to be chosen from RandBox
 * @return Success or failure
 */
int pick_randbox_elem (RandBox *rb, char *elem);

/**
 * Chooses multiple random elements from RandBox
 *
 * @param rb: Reference to RandBox
 * @param choice_list: Array of elements chosen from RandBox
 * @param amount: Amount of elements to be picked
 * @return Success or failure
 */
int pick_randbox_elem_mult (RandBox *rb, char** choice_list, int amount);

#endif
