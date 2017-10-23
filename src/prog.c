void chargement_plan() {
  FILE*fic = fopen("plan.txt", "r");
  char l;
  while ((l=fgetc(fic))!=EOF) {
    printf("%c", l);
  }
}
