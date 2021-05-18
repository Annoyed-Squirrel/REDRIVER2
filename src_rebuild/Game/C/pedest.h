#ifndef PEDEST_H
#define PEDEST_H

#define TANNER_COLLIDER_CARID (MAX_CARS)

extern SVECTOR tannerLookAngle;

extern MODEL* pmTannerModels[17];
extern MODEL* pmJerichoModels[6];

extern SEATED_PEDESTRIANS *seated_pedestrian;
extern int bKillTanner;
extern int bReverseYRotation;

extern PEDESTRIAN *pUsedPeds;

extern void ProcessChairLump(char *lump_file, int lump_size); // 0x00073328

extern void InitTanner(); // 0x0006E408
extern void SetTannerPosition(VECTOR *pVec); // 0x00072478

extern void ProcessTannerPad(PEDESTRIAN *pPed, u_int pad, char PadSteer, char use_analogue); // 0x0006DF54

extern void InitPedestrians(); // 0x0006E5C4
extern void DestroyPedestrians(); // 0x00071F54

extern void DestroyCivPedestrians(); // 0x00072FD0

extern void DestroyPedestrian(PEDESTRIAN *pPed); // 0x00071FB4

extern int ActivatePlayerPedestrian(CAR_DATA *pCar, char *padId, int direction, LONGVECTOR4* position, PED_MODEL_TYPES playerType); // 0x0006E6C4
extern PEDESTRIAN * CreatePedestrian(); // 0x000720AC

extern void PlaceRoadBlockCops(); // 0x0006EC88
extern int CreatePedAtLocation(LONGVECTOR4* pPos, int pedType); // 0x0006F00C

extern void DrawAllPedestrians(); // 0x00072290
extern int TannerActionHappening(); // 0x00072430

extern void ControlPedestrians(); // 0x0006F16C

extern void DeActivatePlayerPedestrian(PEDESTRIAN *pPed); // 0x0007216C

extern void SetupCivPedRouteData(VECTOR *pPos); // 0x0007313C

extern void PingInPedestrians(); // 0x0007047C

extern void TannerCollision(PEDESTRIAN *pPed); // 0x00072EE4

extern int FindPointOfCollision(CAR_DATA *pCar, PEDESTRIAN* pPed); // 0x00070878

extern int TannerCarCollisionCheck(VECTOR *pPos, int dir, int bQuick); // 0x00070A9C

extern int PingOutPed(PEDESTRIAN *pPed); // 0x000731F8

extern void SetupCivJump(PEDESTRIAN *pPed, CAR_DATA *cp); // 0x00071054

extern void SetupCivPedWalk(PEDESTRIAN *pPed); // 0x00073270

extern void HandlePedestrians(); // 0x0007211C

extern void PedestrianActionInit_WalkToTarget(PEDESTRIAN *pPed); // 0x0007283C

extern void CorrectPathPosition(PEDESTRIAN *pedestrian, VECTOR *position); // 0x000715FC

extern int CalcPedestrianDirection(int last_dir, int wx, int wz, VECTOR *target); // 0x00071608

extern int IsPavement(int x, int y, int z, PEDESTRIAN *pPed); // 0x000725B8

extern void SetPedestrianTurn(PEDESTRIAN *pedestrian, int turn); // 0x00072500

extern SEATED_PEDESTRIANS * FindSeated(); // 0x00072644

extern SEATED_PEDESTRIANS * FindTannerASeat(PEDESTRIAN *pPed); // 0x000717AC

extern void add_seated(SEATED_PEDESTRIANS *seatedptr, int seat_index); // 0x000718C8

extern void set_coll_box(int index, CAR_DATA *cp, int offset); // 0x00071A5C

extern void BuildCarCollisionBox(); // 0x00071B7C

extern CAR_DATA * CheckForCar(PEDESTRIAN *pedestrian); // 0x00072738

extern int CheckForPlayerCar(PEDESTRIAN *pedestrian, CAR_COLLISION_BOX *collision_box); // 0x000732C0

extern void CalculatePedestrianInterest(PEDESTRIAN *pPed); // 0x00071E0C

#endif
