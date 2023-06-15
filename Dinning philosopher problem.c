#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>

pthread_mutex_t chopstick[5];

void *philosopher1()
{
    while(1)
    {
        pthread_mutex_lock(&chopstick[4]);
        pthread_mutex_lock(&chopstick[0]);     
        printf("philosopher1 is Eating \n");
        sleep(3);
        pthread_mutex_unlock(&chopstick[4]);
        pthread_mutex_unlock(&chopstick[0]);
        printf("philosopher1 is realesing the chopstick 4 and 0\n");
        printf("philosopher1 is Thinking \n");
    }
    
    pthread_exit(0);
    
}

void *philosopher2()
{
    while(1)
    {
        pthread_mutex_lock(&chopstick[0]);
        pthread_mutex_lock(&chopstick[1]);     
        printf("philosopher2 is Eating \n");
        sleep(3);
        pthread_mutex_unlock(&chopstick[0]);
        pthread_mutex_unlock(&chopstick[2]);
        printf("philosopher2 is realesing the chopstick 0 and 1\n");
        printf("philosopher2 is Thinking \n");
    }
      
    pthread_exit(0);

}
void *philosopher3()
{
    while(1)
    {
        pthread_mutex_lock(&chopstick[1]);
        pthread_mutex_lock(&chopstick[2]);     
        printf("philosopher3 is Eating \n");
        sleep(3);
        pthread_mutex_unlock(&chopstick[1]);
        pthread_mutex_unlock(&chopstick[2]);
        printf("philosopher3 is realesing the chopstick 1 and 2\n");
        printf("philosopher3 is Thinking \n");
    }
    
    pthread_exit(0);
    
}

void *philosopher4()
{
    while(1)
    {
        pthread_mutex_lock(&chopstick[2]);
        pthread_mutex_lock(&chopstick[3]);     
        printf("philosopher4 is Eating \n");
        sleep(3);
        pthread_mutex_unlock(&chopstick[2]);
        pthread_mutex_unlock(&chopstick[3]);
        printf("philosopher4 is realesing the chopstick 2 and 3\n");
        printf("philosopher4 is Thinking \n");
    }
    
    pthread_exit(0);
    
}

void *philosopher5()
{
    while(1)
    {
        pthread_mutex_lock(&chopstick[3]);
        pthread_mutex_lock(&chopstick[4]);     
        printf("philosopher5 is Eating \n");
        sleep(3);
        pthread_mutex_unlock(&chopstick[3]);
        pthread_mutex_unlock(&chopstick[4]);
        printf("philosopher5 is realesing the chopstick 3 and 4\n");
        printf("philosopher5 is Thinking \n");
    }
    
    pthread_exit(0);
    
}

  
int main()
{
    pthread_t ph1,ph2,ph3,ph4,ph5;
    
    for(int i=1; i<=5; i++)
    {
        pthread_mutex_init(&chopstick[i],NULL);
    }
    pthread_create(&ph1,NULL,philosopher1,NULL);
    pthread_create(&ph2,NULL,philosopher2,NULL);
    pthread_create(&ph3,NULL,philosopher3,NULL);
    pthread_create(&ph4,NULL,philosopher4,NULL);
    pthread_create(&ph5,NULL,philosopher5,NULL);
  
    pthread_join(ph1,NULL);
    pthread_join(ph2,NULL);
    pthread_join(ph3,NULL);
    pthread_join(ph4,NULL);
    pthread_join(ph5,NULL);
    return 0;
}


// Compile program : gcc ph.c -o xyz -lpthread
// Run program: ./xyz



