import {
    IsBoolean,
    IsNotEmpty,
    IsString,  
  } from 'class-validator';
  
  export class twoFAActivatedDto {
    @IsString()
    @IsNotEmpty()
    login: string;

    @IsBoolean()
    @IsNotEmpty()
    verified: boolean;
  }