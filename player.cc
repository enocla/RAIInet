export module player;

export import ids;

export class Player {
  public:
    PlayerId id;
    int downloadedData = 0;
    int downloadedViruses = 0;
};
