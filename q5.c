#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Geometry {
    float x, y;
    float width, height;
    int type;
};

void initRectangle(struct Geometry **object);
void initSquare(struct Geometry **object);
void initCircle(struct Geometry **object);
void initLine(struct Geometry **object);

void printGeometry(struct Geometry* object);

void freeGeometry(struct Geometry* object);

#define SCANF_FMT_CIRCLE    "%f %f %f"
#define SCANF_FMT_RECTANGLE "%f %f %f %f"
#define SCANF_FMT_SQUARE    "%f %f %f"
#define SCANF_FMT_LINE      "%f %f %f %f"


#define PRINTF_FMT_CIRCLE    "Circle with center at %f, %f and radius %f\n"
#define PRINTF_FMT_RECTANGLE "Rectangle with corner at (%f, %f) with width %f and height %f\n"
#define PRINTF_FMT_SQUARE    "Square with corner at (%f, %f) and side %f\n"
#define PRINTF_FMT_LINE      "Line from (%f, %f) to (%f, %f)\n"

int main()
{
  int n;
  struct Geometry **object;
  scanf("%d", &n);
  printf("%d geometric items\n", n);

  object = malloc(sizeof(struct Geometry*)*n);

  for(int i = 0; i < n; i++)
  {
    char objectType[40];
    scanf("%s", objectType);

    if(!strcmp(objectType, "Rectangle"))
    {
      initRectangle(&object[i]);
    }
    else if (!strcmp(objectType, "Square"))
    {
      initSquare(&object[i]);
    }
    else if(!strcmp(objectType, "Circle"))
    {
      initCircle(&object[i]);
    }
    else if(!strcmp(objectType, "Line"))
    {
      initLine(&object[i]);
    }
    else
    {
      printf("Unknown geometric type %s\n", objectType);
      exit(1);
    }

  }
  
  for(int i = 0; i < n; i++)
  {
    printGeometry(object[i]);
  }
  
  for(int i = 0; i < n; i++)
  {
    freeGeometry(object[i]);
  }

  free(object);
}

void initRectangle(struct Geometry **object)
{
  *object = malloc(sizeof(struct Geometry));
  (*object)->type = 0;
  scanf(SCANF_FMT_RECTANGLE, &(*object)->x, &(*object)->y, &(*object)->width, &(*object)->height);
}

void initSquare(struct Geometry **object)
{
  *object = malloc(sizeof(struct Geometry));
  (*object)->type = 1;
  scanf(SCANF_FMT_SQUARE, &(*object)->x, &(*object)->y, &(*object)->width);
  (*object)->height = (*object)->width;
}

void initCircle(struct Geometry **object)
{
  *object = malloc(sizeof(struct Geometry));
  (*object)->type = 2;
  scanf(SCANF_FMT_CIRCLE, &(*object)->x, &(*object)->y, &(*object)->width);
  (*object)->height = (*object)->width;
}


void initLine(struct Geometry **object)
{
  *object = malloc(sizeof(struct Geometry));
  (*object)->type = 3;
  scanf(SCANF_FMT_LINE, &(*object)->x, &(*object)->y, &(*object)->width, &(*object)->height);
}

void printGeometry(struct Geometry* object)
{
    switch(object->type)
    {
        case 0:
        printf(PRINTF_FMT_RECTANGLE, object->x, object->y, object->width, object->height);
        break;
        case 1:
        printf(PRINTF_FMT_SQUARE, object->x, object->y, object->width);
        break;
        case 2:
        printf(PRINTF_FMT_CIRCLE, object->x, object->y, object->width);
        break;
        case 3:
        printf(PRINTF_FMT_LINE, object->x, object->y, object->width, object->height);
        break;
        default:
        printf("Unknown geometric type %d\n", object->type);
        exit(1);
    }
}

void freeGeometry(struct Geometry* object)
{
    free(object);
}