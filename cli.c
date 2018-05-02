#include "jpeg.c"

#define HelpMessage "Usage: %s [input] [output]\n" \
            "  -h\tshow usage\n" \
            " Convert option:\n" \
            "  -gs\tto gray scale\n" \

/* Takes a bmp image specified at the command line and
 * encodes it in JPEG format and writes to another file
 * specified at the command line */
int main(int argc, char *argv[])
{
    /* Command line switch for color and greyscale images */
    int num_colors = 3;

    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        printf(HelpMessage, argv[0]);
        return 0;
    }
    if (argc < 3) {
        fprintf(stderr, "argment error\n");
        printf(HelpMessage, argv[0]);
        return 1;
    }

    if (argc == 4 && strcmp(argv[3], "-gs") == 0)
        num_colors = 1;

    char *input = argv[1];
    char *output = argv[2];

    JPEGTimings timings = convertFile(input, output, num_colors, true);

    printf("Read BMP: %f seconds.\n", timings.read_bmp);
    printf("Transform colorspace: %f seconds.\n", timings.transform_colorspace);
    printf("DCT: %f seconds.\n", timings.dct);
    printf("Generate headers: %f seconds.\n", timings.generate_headers);
    printf("Write to file: %f seconds.\n", timings.write_file);
    printf("Total: %f seconds.\n", timings.total);

}
