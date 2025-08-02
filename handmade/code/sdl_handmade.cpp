#include <iostream>
#include <SDL.h>
#include <stdlib.h>

#define internal static
#define local_persist static
#define global_variable static

global_variable SDL_Texture *Texture;
global_variable void *Pixels;
global_variable int TextureWidth;

internal void SDLResizeTexture(SDL_Renderer *Renderer, int Width, int Height)
{
  if (Pixels)
  {
    free(Pixels);
  }
  if (Texture)
  {
    SDL_DestroyTexture(Texture);
  }
  Texture = SDL_CreateTexture(Renderer,
                              SDL_PIXELFORMAT_ARGB8888,
                              SDL_TEXTUREACCESS_STREAMING,
                              Width,
                              Height);
  TextureWidth = Width;
  Pixels = malloc(Width * Height * 4);
}

internal void SDLUpdateWindow(SDL_Window *Window, SDL_Renderer *Renderer)
{
  SDL_UpdateTexture(Texture,
                    0,
                    Pixels,
                    TextureWidth * 4);

  SDL_RenderCopy(Renderer,
                 Texture,
                 0,
                 0);

  SDL_RenderPresent(Renderer);

}

bool HandleEvent(SDL_Event *Event)
{
  bool ShouldQuit = false;

  switch(Event->type)
  {
    case SDL_QUIT:
    {
      printf("SDL_QUIT\n");
      ShouldQuit = true;
    } break;
    case SDL_WINDOWEVENT:
    {
      switch(Event->window.event)
      {
          case SDL_WINDOWEVENT_SIZE_CHANGED:
          {
              SDL_Window *Window = SDL_GetWindowFromID(Event->window.windowID);
              SDL_Renderer *Renderer = SDL_GetRenderer(Window);
              printf("SDL_WINDOWEVENT_SIZE_CHANGED (%d, %d)\n", Event->window.data1, Event->window.data2);
              SDLResizeTexture(Renderer, Event->window.data1, Event->window.data2);
          } break;
          case SDL_WINDOWEVENT_FOCUS_GAINED:
          {
              printf("SDL_WINDOWEVENT_FOCUS_GAINED\n");
          } break;

          case SDL_WINDOWEVENT_EXPOSED:
          {
              SDL_Window *Window = SDL_GetWindowFromID(Event->window.windowID);
              SDL_Renderer *Renderer = SDL_GetRenderer(Window);
              static bool IsWhite = true;
              if (IsWhite == true)
              {
                SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
                IsWhite = false;
              }
              else{
                SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
                IsWhite = true;
              }
              SDL_RenderClear(Renderer);
              SDL_RenderPresent(Renderer);
          }break;
      }
    } break;
  }

  return(ShouldQuit);
}

int main(int argc, char **argv) {

  SDL_Window *Window;

  Window = SDL_CreateWindow("Handmade Hero",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            640,
                            480,
                            SDL_WINDOW_RESIZABLE);

  if (Window)
  {
    SDL_Renderer *Renderer = SDL_CreateRenderer(Window,
                                                -1,
                                                0);
    if (Renderer)
    {

      for(;;)
      {
        SDL_Event Event;
        SDL_WaitEvent(&Event);
        if (HandleEvent(&Event))
        {
          break;
        }
      }

    }
    else{
     // Todo logging 
    }
  }
  else
  {
    // Todo logging
  }


  SDL_Quit();
  return 0;

}
