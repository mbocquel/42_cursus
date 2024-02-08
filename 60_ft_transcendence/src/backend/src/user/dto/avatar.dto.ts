import { IsNotEmpty, IsString, Matches } from "class-validator";

export class AvatarDto {
  @IsString()
  @IsNotEmpty()
  @Matches(/^\d{13}\.\w{3,4}$/g)
  name: string;
}
