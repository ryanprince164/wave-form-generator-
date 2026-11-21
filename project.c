
#include <stdio.h>
#include <math.h>

#define ROWS 21
#define COLS 61

int main()
{
    double A, f, wavelength, phase, time;
    double x, y, velocity;
    int i, j, row;

    char graph[ROWS][COLS];

    printf("=================================\n");
    printf("     WAVEFORM VISUALIZER\n");
    printf("=================================\n");

    printf("Enter Amplitude: ");
    scanf("%lf", &A);

    printf("Enter Frequency (Hz): ");
    scanf("%lf", &f);

    printf("Enter Wavelength (m): ");
    scanf("%lf", &wavelength);

    printf("Enter Phase (degrees): ");
    scanf("%lf", &phase);

    printf("Enter Time (seconds): ");
    scanf("%lf", &time);

    if (A <= 0 || f <= 0 || wavelength <= 0)
    {
        printf("Invalid input! Values must be positive.\n");
        return 1;
    }

    velocity = f * wavelength;
    phase = phase * 3.14159265 / 180.0;

    // Initialize graph
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            graph[i][j] = ' ';
        }
    }

    // Draw horizontal axis
    for (j = 0; j < COLS; j++)
        graph[ROWS / 2][j] = '-';

    // Draw vertical axis
    for (i = 0; i < ROWS; i++)
        graph[i][0] = '|';

    graph[ROWS / 2][0] = '+';

    // Calculate wave points
    for (j = 0; j < COLS; j++)
    {
        x = (2.0 * wavelength * j) / (COLS - 1);

        y = A * sin(2 * 3.14159265 * f * time
                    - 2 * 3.14159265 * x / wavelength
                    + phase);

        row = (int)round(
            (ROWS - 1) / 2.0
            - (y / A) * ((ROWS - 1) / 2.0 - 1)
        );

        if (row >= 0 && row < ROWS)
            graph[row][j] = '*';
    }

    // Display graph
    printf("\n       GENERATED WAVEFORM\n\n");

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
            printf("%c", graph[i][j]);

        printf("\n");
    }

    printf("\nAmplitude = %.2lf\n", A);
    printf("Frequency = %.2lf Hz\n", f);
    printf("Wavelength = %.2lf m\n", wavelength);
    printf("Wave Velocity = %.2lf m/s\n", velocity);

    printf("\nWave generated successfully!\n");

    return 0;
}
