import {
    IsNotEmpty,
    IsString,  
  } from 'class-validator';
  
  export class TfaToken {
    @IsString()
    @IsNotEmpty()
    key: string;

    @IsString()
    @IsNotEmpty()
    tfa_token: string;
  }