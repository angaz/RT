int main()
{
	pthread_t	tid[2];

	for(int i = 0; i < 2; i++)
		pthread_create(&tid[i], NULL, routine, NULL);
	for(int i = 0; i < 2;, i++)
		pthread_join(tid[i], NULL);
	return 0;
}
