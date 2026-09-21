#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int token = 0;
    if (rank == 0) {
        token = 42;
        MPI_Send(&token, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("rank=%d sent token=%d to rank=1\n", rank, token);
    } else if (rank == 1) {
        MPI_Recv(&token, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("rank=%d received token=%d from rank=0\n", rank, token);
    }

    MPI_Finalize();
    return 0;
}
