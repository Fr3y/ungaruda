// Ungaruda
// COpyright (C) Abdul karim kikar 2020
// Licensed under GPL 3.0
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char ** argv) {
  int i;
  char* ver = "1.0.0"; // If you do not change this every update then the gods will punish you. unless its a minor bug fix or somehting.
  static struct option long_options[] = {
    {"browser",no_argument,NULL,'b'},
	{"grub",no_argument,NULL,'g'},
	{"system", no_argument, NULL, 's'},
	{"all", no_argument, NULL, 'a'},
	{"annoying", no_argument, NULL, 'y'},
	{"help", no_argument, NULL, 'h'},
	{"version", no_argument, NULL, 'v'},
	{"replace", required_argument, NULL, 'r'},
    {NULL,0,NULL,0}
  };

  char ch;
  int grub = 0;
  int systemz = 0;
  int all = 0;
  while ((ch = getopt_long(argc, argv, "bgsayhvr:", long_options, NULL)) != -1) {
    switch (ch) {
    case 'b':
      printf("Removing all garuda browser extensions\n");
	  system("pkexec pacman -R firefox-extension-google-search-link-fix firefox-dark-reader firefox-decentraleyes firefox-extension-canvasblocker firefox-extension-https-everywhere firefox-extension-keepassxc-browser firefox-extension-privacybadger firefox-extension-xdm-browser-monitor firefox-ublock-origin xdman-2020 garuda-firefox");
      exit(0);
    case 'g':
	  grub = 1;
      printf("Removing all garuda GRUB packages.\n");
	  system("pkexec pacman -R grub-garuda grub-theme-garuda os-prober-garuda");
      break;
    case 's':
      systemz = 1;
	  printf("Removing all garuda system packages.\n");
	  system("pkexec pacman -R plymouth-theme-garuda garuda-welcome-git garuda-bluetooth garuda-boot-options-git garuda-gstreamer garuda-hooks garuda-ibus garuda-icons garuda-input garuda-modem garuda-network garuda-network-assistant-git garuda-settings-manager-git garuda-settings-manager-knotifier-git garuda-settings-samba garuda-vaapi garuda-wallpapers garuda-welcome-git garuda-xfce-settings garuda-zsh-config");
      break;
    case 'a':
	  all = 1;
      printf("Removing all garuda packages.\n");
	  system("pkexec pacman -R grub-garuda grub-theme-garuda os-prober-garuda plymouth-theme-garuda garuda-browser-settings firefox-dark-reader firefox-extension-google-search-link-fix garuda-firefox firefox-decentraleyes firefox-extension-canvasblocker firefox-extension-https-everywhere firefox-extension-keepassxc-browser firefox-extension-privacybadger firefox-extension-xdm-browser-monitor firefox-ublock-origin xdman-2020 garuda-welcome-git garuda-bluetooth garuda-boot-options-git garuda-gstreamer garuda-hooks garuda-ibus garuda-icons garuda-input garuda-modem garuda-network garuda-network-assistant-git garuda-settings-manager-git garuda-settings-manager-knotifier-git garuda-settings-samba garuda-vaapi garuda-wallpapers garuda-welcome-git garuda-xfce-settings garuda-zsh-config");
      break;
    case 'y':
	  printf("Removing all annoying garuda packages.\n");
	  system("pkexec pacman -R garuda-welcome-git garuda-browser-settings firefox-extension-google-search-link-fix garuda-firefox firefox-dark-reader firefox-decentraleyes firefox-extension-canvasblocker firefox-extension-https-everywhere firefox-extension-keepassxc-browser firefox-extension-privacybadger firefox-extension-xdm-browser-monitor firefox-ublock-origin xdman-2020");
	  exit(0);
	case 'h':
      printf("Ungaruda Help:\n");
      printf("Usage: [-bgsayhvr].\n");
      printf("-b, --browser: Removes all default garuda browser extensions (+ Xtreme Download Manager).\n");
      printf("-g, --grub: Removes all Gruda GRUB packages (not recommended)\n");
      printf("-s, --system: Removes all System packages, (Non-GRUB packages) (not recommended).\n");
      printf("-a, --all: Removes all garuda packages, Including GRUB.\n");
      printf("-y, --annoying: Removes annoying packages (Browser extensions + Xtreme Download Manager + Garuda-welcome).\n");
	  printf("-h, --help: prints this message.\n");
	  printf("-v, --version: prints current version.\n");
	  printf("-r, --replace [s/g/a]: Replaces garuda packages with default packages (Only compatible with System, Grub or All.)\n");
	  printf("replace can't replace all garuda packages, it is not a effective method to install garuda-free packages. Try running sudo pacman -Syu\n");
	  printf("NOTE: Remove the chaotic-aur repo so that you can't install garuda packages.\n");
      exit(0);
	case 'v':
      printf(ver);
      exit(0);
	case 'r':
	  printf("Replacing packages...\n");
	  if (all == 1) {
		  printf("Replacing all garuda packages...\n");
		  system("pkexec pacman -S blueman gstreamer ibus networkmanager grub os-prober");
		  exit(0);
	  }
	  if (systemz == 1) {
		  printf("Replacing garuda system packages with blueman, gstreamer, ibus and networkmanager\n");
		  system("pkexec pacman -S blueman gstreamer ibus networkmanager");
		  break;
	  }
	  if (grub == 1) {
		  printf("Replacing garuda grub packages with grub.\n");
		  system("pkexec pacman -S grub os-prober");
		  break;
	  }
    }
  }

  argc -= optind;
  argv += optind;
  if (argc < 1) {
  	printf("%s", "use ungaruda --help.\n");
  	return 0;
  }
}