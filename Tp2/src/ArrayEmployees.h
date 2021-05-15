
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;




/** \brief mustra el menu
 *
 * \return la opcion elegida
 */
int menu();

/** \brief mustra el menu
 *
 * \return la opcion elegida
 */
int subMenuModify();


/** \brief muestra un empleado
 *
 * \param  el emplaedo
 * \return void
 */
void printEmployee(eEmployee anEmployee);


/** \brief muestra la lista de los empleados
 *
 * \param list[] eEmployee lista de empleados
 * \param len int tamaño del array
 * \return void
 *
 */
void printEmployees(eEmployee list[], int len);


/** \brief inicializa la lista de empledos
 *
 * \param list[] eEmployee lista de empleados
 * \param len int tamaño del array
 * \return int retorna 1 si todo OK
 *                     0 si hay errores
 *
 */
int initEmployees(eEmployee list[], int len); // Inicializar emp


/** \brief agrega un empleado a la lista
 *
 * \param list[] eEmployee lista de empleados
 * \param len int tamaño def array
 * \param pID int* puntero a un prox id
 * \return int retorna 1 si todo OK
 *                 0 si hay errores
 *
 */
int addEmployee(eEmployee list[], int len, int* pID); // Alta emp


/** \brief elimina un empleado de la lista
 *
 * \param list[] eEmployee lista de empleados
 * \param len int tamaño del array
 * \return int retorna 1 si todo OK
 *                 0 si hay errores
 *
 */
int removeEmployee(eEmployee list[], int len); // Baja emp


/** \brief  modifica un empleado
 *
 * \param list[] eEmployee lista de empleados
 * \param len int tamaño del array
 * \return int retorna 1 si todo OK
 *                 0 si hay errores
 *
 */
int modifyEmployee(eEmployee list[], int len); // Modificar emp


/** \brief busca un empleado por id
 *
 * \param list[] eEmployee lista de  empleados
 * \param len int tamaño del arryay
 * \param id int id a buscar
 * \return int retorna 1 si todo OK
 *                 0 si hay errores
 *
 */
int findEmployeeById(eEmployee list[], int len,int id); // Buscar emp


/** \brief busca un lugar libre en el array
 *
 * \param list[] eEmployee lista de empleados
 * \param len int tamaño del array
 * \return int retorna 1 si todo OK
 *                 0 si hay errores
 *
 */
int findEmptyEmployee(eEmployee list[], int len); // Buscar lugare libre


/** \brief ordenar lista de empleados
 *
 * \param list[] eEmployee lista de empleados
 * \param len int tamaño del array
 * \return int retorna 1 si todo OK
 *                 0 si hay errores
 *
 */
int sortEmployees(eEmployee list[], int len); // Ordenar emp


/** \brief suma total de salarios y promedio de ellos
 *
 * \param list[] eEmployee lista de empleados
 * \param len int tamaño del array
 * \param numbersEmp int cantidad de empleados
 * \return int retorna 1 si todo OK
 *                 0 si hay errores
 *
 */
int totalAndAverage(eEmployee list[], int len, int numbersEmp);

