function StringField(props: {
  placeholder: string;
  value: string;
  maxLength: number;
  onChange: Function;
}) {
  return (
    <input
      name="stringFieldInput"
      type="text"
      placeholder={props.placeholder}
      value={props.value}
      maxLength={props.maxLength}
      onChange={(e) => props.onChange(e.target.value)}
    />
  );
}

export default StringField;
