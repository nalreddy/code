/* If conditional variable is available to used together with mutex 
 */
typedef semaphore_s {
    pthread_mutex_t mx;
    pthread_cond_t   cv;
    int ctr;
} sem_t;

void sem_init(sem_t *sem, int count) {
   pthread_mutex_init(&sem->mx);
   pthread_cond_init(&sem->cv);
   sem->ctr=count;
}

void sem_wait(sem_t *sem) {
    pthread_mutex_lock(&sem->mx);
    while(sem->ctr==0) pthread_cond_wait(&sem->cv, &sem->mx);
    sem->ctr--;
    pthread_mutex_unlock(&sem->mx);
}

void sem_post(sem_t *sem) {
   pthread_mutex_lock(&sem->mx);
   if(sem->ctr++==0) pthread_cond_broadcast(&sem->cv);
   pthread_mutex_unlock(&sem->mx);
}
