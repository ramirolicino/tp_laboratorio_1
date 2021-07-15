/** \brief un controlador que se usa para cargar un archivo en modo de texto
 *
 * \param path char* el archivo seleccionado
 * \param pArrayListEmployee LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/** \brief un controlador que se usa para cargar un archivo en modo binario
 *
 * \param path char* el archivo seleccionado
 * \param pArrayListEmployee LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief un controlador que se usa para agregar un empleado
 *
 * \param pArrayListEmployee LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);


/** \brief un controlador que se usa para modificar un empleado
 *
 * \param pArrayListEmployee LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief un controlador que se usa para eliminar un empleado
 *
 * \param pArrayListEmployee LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief un controlador que se usa para listar los empleados
 *
 * \param pArrayListEmployee LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief un controlador que se usa para ordenar un empleado
 *
 * \param pArrayListEmployee LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief un controlador que se usa para guardar un archivo en modo de texto
 *
 * \param path char* el archivo seleccionado
 * \param pArrayListEmployee LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief un controlador que se usa para guardar un archivo en modo de binario
 *
 * \param path char* el archivo seleccionado
 * \param pArrayListEmployee LinkedList* puntero al array creado
 * \return int retorna -1->error
 *                      0->todo ok
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


