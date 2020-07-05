#define LIBRE 1
#define OCUPADO 0

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;


/** \brief To indicate that all position in the array are empty, this function put the flag(isEmpty) in TRUE in all
 *          position of the array.
 * \param listEmployees[] eEmployee
 * \param lenEmployees int
 * \return int return (-1) if error [Invalid length or null pointer] - (0) if OK
 *
 */
int initEmployees(eEmployee listEmployees[], int lenEmployees);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param listEmployees[], employee
* \param lenEmployees int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(eEmployee listEmployees[], int lenEmployees, char name[],char
lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param listEmployees[] Employee
* \param lenEmployees int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(eEmployee listEmployees[], int lenEmployees,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 2)
*
* \param listEmployees[] Employee
* \param lenEmployees int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(eEmployee listEmployees[], int lenEmployees, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param listEmployees[] Employee
* \param lenEmployees int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(eEmployee listEmployees[], int lenEmployees, int order);

/** \brief print the content of employees array
*
* \param listEmployees[] Employee
* \param lenEmployees int
* \return int
*
*/
int printEmployees(eEmployee listEmployees[], int lenEmployees);

/** \brief print an employee
 *
 * \param myEmployee eEmployee
 * \return void
 *
 */
void printEmployee(eEmployee myEmployee);

/** \brief Receive position for modify and modify it
 *
 * \param listEmployees[] eEmployee
 * \param position int
 * \return int
 *
 */
int modifyEmployee(eEmployee listEmployees[], int position);

/** \brief calculates and prints total wages, average, and how many employees exceed that average
 *
 * \param listEmployees[] eEmployee
 * \param lenEmployees int
 * \return void
 *
 */
void calcSalary(eEmployee listEmployees[], int lenEmployees);

/** \brief Search if listEmployees[] have any employee
 *
 * \param listEmployees[] eEmployee
 * \param lenEmployees int
 * \return int Return 1 if found at least 1 - 0 if not found anyone
 *
 */
int haveEmployees(eEmployee listEmployees[], int lenEmployees);
