#include <sys/wait.h>
#include <sys/time.h>
#include <string>
#include <dirent.h>

void displayProcessInfo(const char *prefix) {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    printf("%s PID: %d, PPID: %d, Time: %02ld:%02ld:%02ld.%03ld\n",
           prefix, pid, ppid, tv.tv_sec / 3600 % 24, (tv.tv_sec / 60) % 60, tv.tv_sec % 60, tv.tv_usec / 1000);
}

void compareFiles(char *file1, char *file2) {
    FILE *fp1 = fopen(file1, "rb");
    FILE *fp2 = fopen(file2, "rb");

    if (fp1 == nullptr || fp2 == nullptr) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    char ch1, ch2;
    long byteCount = 0;
    int areEqual = 1;

    while (1) {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);

        if (ch1 != ch2) {
            areEqual = 0;
            break;
        }

        if (ch1 == EOF || ch2 == EOF) {
            break;
        }

        byteCount++;
    }

    fclose(fp1);
    fclose(fp2);

    if (areEqual) {
        printf("Files %s and %s are identical. Bytes compared: %ld\n", file1, file2, byteCount);
    } else {
        printf("Files %s and %s are different.\n", file1, file2);
    }
}

void processDir(char *dir1, char *dir2, int maxProcesses) {
    DIR *dp1, *dp2;
    struct dirent *entry1, *entry2;
    int processCount = 0;

    dp1 = opendir(dir1);

    if (dp1 == nullptr) {
        perror("Error opening directories");
        exit(EXIT_FAILURE);
    }

    while ((entry1 = readdir(dp1)) != nullptr) {
        dp2 = opendir(dir2);
        if(dp2 == nullptr){
            perror("Error opening directories");
            exit(EXIT_FAILURE);
        }
        while((entry2 = readdir(dp2)) != nullptr) {
            if (entry1->d_type == DT_REG && entry2->d_type == DT_REG) {
                // Only process regular files

                // Create a child process to compare files
                pid_t pid = fork();

                if (pid == 0) {
                    // Child process
                    char file1[256];
                    char file2[256];
                    snprintf(file1, sizeof(file1), "%s/%s", dir1, entry1->d_name);
                    snprintf(file2, sizeof(file2), "%s/%s", dir2, entry2->d_name);

                    displayProcessInfo("Child");
                    compareFiles(file1, file2);

                    exit(EXIT_SUCCESS);
                } else if (pid < 0) {
                    perror("Fork failed");
                    exit(EXIT_FAILURE);
                } else {
                    // Parent process
                    processCount++;
                    if (processCount >= maxProcesses) {
                        wait(nullptr); // Wait for a child process to finish
                        processCount--;
                    }
                }
            }
        }
        closedir(dp2);
    }

    closedir(dp1);

    // Wait for all child processes to finish
    while (processCount > 0) {
        wait(nullptr);
        processCount--;
    }
}

int main() {
    char dir1[256];
    char dir2[256];
    int maxProcesses;

    printf("Enter the first directory: ");
    scanf("%s", dir1);

    printf("Enter the second directory: ");
    scanf("%s", dir2);

    printf("Enter the maximum number of concurrent processes (N): ");
    scanf("%d", &maxProcesses);

    displayProcessInfo("Parent");

    processDir(dir1, dir2, maxProcesses);

    // Run 'ps -x' using system()
    printf("Running 'ps -x' in the parent process:\n");
    system("ps -x");

    return 0;
}